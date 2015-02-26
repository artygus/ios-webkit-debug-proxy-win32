iOS WebKit Debug Proxy Win32
============================

Win32 port of ios-webkit-debug-proxy (https://github.com/google/ios-webkit-debug-proxy).

The ios-webkit-debug-proxy allows developers to inspect MobileSafari and UIWebViews on real and simulated iOS devices via the [DevTools UI](https://developers.google.com/chrome-developer-tools/) and [WebKit Remote Debugging Protocol](https://developers.google.com/chrome-developer-tools/docs/remote-debugging).  DevTools requests are translated into Apple's [Remote Web Inspector service](https://developer.apple.com/technologies/safari/developer-tools.html) calls.

For more info please refer to the original [README](proxy.md)


Binaries
--------

Get latest build from SourceForge : [Release](http://sourceforge.net/projects/ios-webkit-debug-proxy-win32/files/ios-webkit-debug-proxy-win32.zip/download) / [Debug](http://sourceforge.net/projects/ios-webkit-debug-proxy-win32/files/ios-webkit-debug-proxy-win32-debug.zip/download)


Why win32 port?
---------------

Of course you can use any vm software to compile and run original ios-webkit-debug-proxy and forward usb/ports but it's not very cool, isn't it?


Notes
-----

- To debug with with ios-webkit-debug-proxy you need to have iTunes installed (after installation you can safely remove iTunes from Programs and Features, just leave Apple Mobile Device Support and Apple Application Support applications)
- The project compilation was tested with VS2012 and VS2013 only


Troubleshooting
---------------

- If when starting app you get the "connect: No error" message, please check that Apple Mobile Device service is running
- If you see open pages of the iOS device for debugging, but when click on them you get a blank dev tools window just click on the shield icon in the address bar and choose "Load unsafe script"


Third Party Libraries
---------------------

Library | License | Project Link
------- | ------- | ----
libiconv\* | LGPL | http://www.gnu.org/software/libiconv/
libgcc\* | GPL / GCC Runtime Library Exception | https://gcc.gnu.org
libxml2\* | MIT | http://xmlsoft.org
openssl\* | OpenSSL | http://www.openssl.org
pcre\* | BSD | www.pcre.org
zlib\* | zlib | http://www.zlib.net
libimobiledevice | LGPL 2.1 | www.libimobiledevice.org<br/>win32 port https://github.com/MCE-KobyBo/libimobiledevice
usbmuxd | LGPL 2.1 | www.libimobiledevice.org<br />win32 port https://github.com/MCE-KobyBo/usbmuxd
libplist | LGPL 2.1 | www.libimobiledevice.org<br />win32 port https://github.com/MCE-KobyBo/libplist


\* win32 binaries provided by http://gnuwin32.sourceforge.net
