import urllib.request
import os
import sys
import re

def get_gossip():
    feed_url = os.getenv("RSS_FEED")
    search_term = sys.argv[1] if len(sys.argv) > 1 else ""
    
    try:
        req = urllib.request.Request(feed_url, headers={'User-Agent': 'Mozilla/5.0'})
        with urllib.request.urlopen(req) as response:
            html = response.read().decode('utf-8')
            # Ищем заголовки в RSS (упрощенно)
            titles = re.findall(r'<title>(.*?)</title>', html)
            for title in titles:
                if search_term.lower() in title.lower():
                    print(title)
    except Exception as e:
        print(f"Ошибка чтения потока: {e}")

if __name__ == "__main__":
    get_gossip()
