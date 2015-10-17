/** 
Sends information to Google Translate's tts service and then plays it back.
*/

import java.net.*;
import java.io.*;
import java.util.*;
import javax.sound.sampled.*;
import javafx.scene.media.*;
import java.awt.*;
public class Pronounce {
	private static final int MAX = 100;
	
	private static String WITH_DELIM(String str) {
		return String.format("(?<=[%s])",str);
	}
	
	private static String[] patterns = {
		WITH_DELIM("\\.\\;\\?"),
		WITH_DELIM("\\,"),
		WITH_DELIM(" "),
		String.format(".{%d}",MAX)
	};
	private static void _splitString(ArrayList<String> res, String str, int curPattern) {
		if (str.length()<=MAX) { 
			res.add(str);
			return;
		}
		String[] tmp = str.split(patterns[curPattern]);
		for (int i = 0; i < tmp.length; ++i) {
			if (res.size() > 0) {
				String cur = res.get(res.size()-1);
				if (cur.length() + tmp[i].length() <= MAX) {
					cur += tmp[i];
					res.set(res.size()-1, cur);
					continue;
				}
			} 
			if (tmp[i].length() <= MAX) {
				res.add(tmp[i]);
			} else {
				_splitString(res,tmp[i],curPattern+1);
			}	
			
		}
	}

	//splits the string where there's a '|'
	public static ArrayList<String> splitString(String str) {
		ArrayList<String> res = new ArrayList<>();
		_splitString(res,str,0);
		return  res;
	}

	public static ArrayList<URL> buildQuery(String language, String query) {
		ArrayList<URL> res = new ArrayList<>();
		ArrayList<String> texts = splitString(query);
		System.out.println("Query="+texts);
		for (int i = 0; i < texts.size(); ++i) {
			try {
				URL cur = new URL("http://www.translate.google.com/translate_tts?tl="+
								language+
								"&q="+URLEncoder.encode(texts.get(i),"UTF-8")+
								"&total="+texts.size()+
								"&idx="+i
								);
				res.add(cur);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		return res;
	}
	
	public static void say(String language, String text) {
		try {
			ArrayList<URL> urls = buildQuery(language,text);
			System.out.println(String.format("Need %d queries",urls.size()));
			File file = File.createTempFile("tts",".mp3");
			OutputStream out = new FileOutputStream(file);
			for (URL url : urls) {
				URLConnection connection = url.openConnection();
				connection.setRequestProperty("User-Agent","Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.115 Safari/537.36");
				connection.setRequestProperty("Referer","http://www.gstatic.com/translate/sound_player2.swf");
				connection.connect();
				System.out.println(url.toString());
				InputStream is = new BufferedInputStream(connection.getInputStream());
				int c;
				while((c=is.read())>=0)
					out.write(c);
				is.close();
			}
			out.close();
			playMP3(file);
			//Desktop.getDesktop().open(file);
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}
	}
	
	public static void say_en(String text) {
		say("en",text);
	}
	
	public static void playMP3(File file) {
		MediaPlayer mp = new MediaPlayer(new Media(file.toURI().toString()));
		try {
			System.out.print("Waiting for media player...");
			while(mp.getStatus()!=MediaPlayer.Status.READY)
				Thread.sleep(10);
			System.out.print("\r                                  \r");
		} catch (Exception e) {
			e.printStackTrace();
		}
		mp.play();
		try {
			System.out.println("Sleeping " + mp.getTotalDuration());
			Thread.sleep((long)mp.getTotalDuration().toMillis());
		} catch (Exception e) {
			e.printStackTrace();
		}
		mp.dispose();
	}
	
	public static void main(String[] args) throws Exception{
		new javafx.embed.swing.JFXPanel(); // forces JavaFX init
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String text;
		System.out.println("Usage:");
		System.out.println("[language code|]<text to speech>");
		System.out.println("examples:");
		System.out.println("Hi");
		System.out.println("fr|Bonjour");
		System.out.println("ja|English");
		System.out.println();
		while ((text=in.readLine())!=null&&text.length()>0) {
			String[] texts = text.split("\\|");
			if (texts.length == 2)
				say(texts[0],texts[1]);
			else
				say_en(text);
		}
		in.close();
		System.exit(0);
	}
}