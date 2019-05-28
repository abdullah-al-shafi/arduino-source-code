# AT কম্যান্ড :

এখন আমরা একটি মৌলিক সংযোগ স্থাপন করেছি চলুন সিরিয়াল মনিটর এর মাধ্যমে AT কমান্ড পাঠিয়ে SIM800 মডিউল দিয়ে যোগাযোগ করার চেষ্টা করি।

AT কমান্ডটি SIM 800A  ফাংশনগুলি চালানোর জন্য ব্যবহৃত হয় । আমরা এই কোডগুলি Arduino এর মাধ্যমে প্রেরণ করি এবং এটি নির্বাহের জন্য SIM800 এ কমান্ড 
রিলে করবে।আপনি ব্যবহার করতে পারেন সবচেয়ে মৌলিক এটি কমান্ড "AT"। যখন আপনি সিরিয়াল মনিটরে এই কমান্ড টাইপ করেন বা অনুরোধ করেন তখন 
প্রতিক্রিয়াটি "AT" হিসাবেও থাকবে। এই প্রতিক্রিয়াটি যাচাই করে যে Arduino SIM800 এর সাথে সঠিকভাবে 
যোগাযোগ করছে।
AT //সিরিয়াল যোগাযোগ প্রতিষ্ঠিত
আমরা এই রকম আরও বিভিন্ন কম্যান্ড ব্যাবহার করে বিভিন্ন রকম কাজ কড়তে পারি।
 
 # ইন্টারনেট থেকে সহজে একটি ওয়েব পেজ ডাউনলোড করা
 
আসুন যাচাই করার জন্য প্রথমে "AT + CSQ" টাইপ করে সিগন্যালের গুণমানটি পরীক্ষা করি।

AT+CSQ // সিগন্যাল চেক করার জন্য।
পরবর্তী ধাপ এ আমরা ডিভাইসটি সম্পূর্ণ কার্যকারিতা মোডে সেট করব।এইটা ডিফল্ট ঠাকে।তার পরও শিওর হবার জন্য 
AT+CFUN=1 //সম্পূর্ণ কার্যকারিতা মোড
পরবর্তী ধাপ এ আমরা ডাটা নেটওয়ার্কে কানেক্ট করব।
AT+CGATT=1 //একটি জিপিআরএস নেটওয়ার্ক সংযুক্ত করে
আমরা এখন সেটিং ঈম্পোট করব।
AT+SAPBR=3,1,"CONTYPE","GPRS" //Configure bearer profile 1
AT+SAPBR=3,1,"APN","internet" //"internet" is APN for Smart
AT+SAPBR=1,1 //To open a GPRS context
এরপরে, আসুন SIM800 এর জন্য ব্রাউজারের মতো পরিবেশ সেট করে একটি ওয়েব সেশন স্থাপন করি। প্রথম আমরা HTTP সেটিংস ইনিশিয়াল এবং সেট করব। 
AT+HTTPINIT //Init HTTP service
AT+HTTPPARA="CID",1 //Set parameters for HTTP session
AT+HTTPPARA="REDIR",1 //Auto redirect
 এখন আমারা একটা ইচ্ছা মতো ওয়েব সাইড এর URL দিয়ে সেটি ডাওণলোয়াড করব।
AT+HTTPPARA="URL","http://google.com"

এখন আমারা SIM800A কে ডাওণলোয়াড শুরু করতে বলব। 
AT+HTTPACTION=0 //Get session start
যখন ওয়েব পেজটি ডাওণলোয়াড হয়ে জাবে। সিরিয়াল মনিটর এ ওই পেজ এর পূর কন্টেন্ট দেখা যাবে। 
AT+HTTPREAD //Read the data of the HTTP server

# লোকেশন জানার জন্যঃ

AT+CLBSCFG=0,2 //Get Times have use positioning command
AT+CLBS=1,1 //Get current longitude, latitude and precision
AT+CLBS=3,1 //Get access times
AT+CLBS=4,1 //Get longitude, latitude, precision and date time

AT+CGATT =1 // to attach GPRS.

AT+SAPBR =3,1,”CONTYPE”,”GPRS” //activate bearer profile.

AT+SAPBR =3,1,”APN”,”RCMNET”

AT+SAPBR=1,1

AT+SAPBR=2,1

AT+CIPGSMLOC=1,1 //to get gsm location, time and date.

AT+CIPGSMLOC=2,1 //to get gsm time and date

AT+SAPBR =0,1 //to deactivate bearer profile.

# মোবাইল এর টাকা চেক করতে 

AT+CUSD=1,''*566#''
