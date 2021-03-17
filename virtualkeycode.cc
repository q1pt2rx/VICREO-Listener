#include <napi.h>
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

#ifdef _WIN32
	#define WINVER 0x0500
	#include <windows.h>
#endif

using namespace std;

std::map<std::string, int> mapOfVKCodes;

void defineKeys()
{
	// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	mapOfVKCodes.insert(std::make_pair("leftmouse", 0x01));
	mapOfVKCodes.insert(std::make_pair("rightmouse", 0x02));
	mapOfVKCodes.insert(std::make_pair("middlemouse", 0x04));
	mapOfVKCodes.insert(std::make_pair("x1mouse", 0x05));
	mapOfVKCodes.insert(std::make_pair("x2mouse", 0x06));
	mapOfVKCodes.insert(std::make_pair("backspace", 0x08));
	mapOfVKCodes.insert(std::make_pair("tab", 0x09));
	mapOfVKCodes.insert(std::make_pair("enter", 0x0D));
	mapOfVKCodes.insert(std::make_pair("shift", 0x10));
	mapOfVKCodes.insert(std::make_pair("ctrl", 0x11));
	mapOfVKCodes.insert(std::make_pair("alt", 0x12));
	mapOfVKCodes.insert(std::make_pair("pause", 0x13));
	mapOfVKCodes.insert(std::make_pair("capslock", 0x14));
	mapOfVKCodes.insert(std::make_pair("esc", 0x1B));
	mapOfVKCodes.insert(std::make_pair("spacebar", 0x20));
	mapOfVKCodes.insert(std::make_pair(" ", 0x20));
	mapOfVKCodes.insert(std::make_pair("pageup", 0x21));
	mapOfVKCodes.insert(std::make_pair("pagedown", 0x22));
	mapOfVKCodes.insert(std::make_pair("end", 0x23));
	mapOfVKCodes.insert(std::make_pair("home", 0x24));
	mapOfVKCodes.insert(std::make_pair("left", 0x25));
	mapOfVKCodes.insert(std::make_pair("up", 0x26));
	mapOfVKCodes.insert(std::make_pair("right", 0x27));
	mapOfVKCodes.insert(std::make_pair("down", 0x28));
	mapOfVKCodes.insert(std::make_pair("printscreen", 0x2C));
	mapOfVKCodes.insert(std::make_pair("ins", 0x2D));
	mapOfVKCodes.insert(std::make_pair("del", 0x2E));
	mapOfVKCodes.insert(std::make_pair("help", 0x2F));
	mapOfVKCodes.insert(std::make_pair("0", 0x30));
	mapOfVKCodes.insert(std::make_pair("1", 0x31));
	mapOfVKCodes.insert(std::make_pair("2", 0x32));
	mapOfVKCodes.insert(std::make_pair("3", 0x33));
	mapOfVKCodes.insert(std::make_pair("4", 0x34));
	mapOfVKCodes.insert(std::make_pair("5", 0x35));
	mapOfVKCodes.insert(std::make_pair("6", 0x36));
	mapOfVKCodes.insert(std::make_pair("7", 0x37));
	mapOfVKCodes.insert(std::make_pair("8", 0x38));
	mapOfVKCodes.insert(std::make_pair("9", 0x39));
	mapOfVKCodes.insert(std::make_pair("a", 0x41));
	mapOfVKCodes.insert(std::make_pair("b", 0x42));
	mapOfVKCodes.insert(std::make_pair("c", 0x43));
	mapOfVKCodes.insert(std::make_pair("d", 0x44));
	mapOfVKCodes.insert(std::make_pair("e", 0x45));
	mapOfVKCodes.insert(std::make_pair("f", 0x46));
	mapOfVKCodes.insert(std::make_pair("g", 0x47));
	mapOfVKCodes.insert(std::make_pair("h", 0x48));
	mapOfVKCodes.insert(std::make_pair("i", 0x49));
	mapOfVKCodes.insert(std::make_pair("j", 0x4A));
	mapOfVKCodes.insert(std::make_pair("k", 0x4B));
	mapOfVKCodes.insert(std::make_pair("l", 0x4C));
	mapOfVKCodes.insert(std::make_pair("m", 0x4D));
	mapOfVKCodes.insert(std::make_pair("n", 0x4E));
	mapOfVKCodes.insert(std::make_pair("o", 0x4F));
	mapOfVKCodes.insert(std::make_pair("p", 0x50));
	mapOfVKCodes.insert(std::make_pair("q", 0x51));
	mapOfVKCodes.insert(std::make_pair("r", 0x52));
	mapOfVKCodes.insert(std::make_pair("s", 0x53));
	mapOfVKCodes.insert(std::make_pair("t", 0x54));
	mapOfVKCodes.insert(std::make_pair("u", 0x55));
	mapOfVKCodes.insert(std::make_pair("v", 0x56));
	mapOfVKCodes.insert(std::make_pair("w", 0x57));
	mapOfVKCodes.insert(std::make_pair("x", 0x58));
	mapOfVKCodes.insert(std::make_pair("y", 0x59));
	mapOfVKCodes.insert(std::make_pair("z", 0x5A));
	mapOfVKCodes.insert(std::make_pair("leftwindows", 0x5B));
	mapOfVKCodes.insert(std::make_pair("rightwindows", 0x5C));
	mapOfVKCodes.insert(std::make_pair("sleep", 0x5F));
	mapOfVKCodes.insert(std::make_pair("num0", 0x60));
	mapOfVKCodes.insert(std::make_pair("num1", 0x61));
	mapOfVKCodes.insert(std::make_pair("num2", 0x62));
	mapOfVKCodes.insert(std::make_pair("num3", 0x63));
	mapOfVKCodes.insert(std::make_pair("num4", 0x64));
	mapOfVKCodes.insert(std::make_pair("num5", 0x65));
	mapOfVKCodes.insert(std::make_pair("num6", 0x66));
	mapOfVKCodes.insert(std::make_pair("num7", 0x67));
	mapOfVKCodes.insert(std::make_pair("num8", 0x68));
	mapOfVKCodes.insert(std::make_pair("num9", 0x69));
	mapOfVKCodes.insert(std::make_pair("f1", 0x70));
	mapOfVKCodes.insert(std::make_pair("f2", 0x71));
	mapOfVKCodes.insert(std::make_pair("f3", 0x72));
	mapOfVKCodes.insert(std::make_pair("f4", 0x73));
	mapOfVKCodes.insert(std::make_pair("f5", 0x74));
	mapOfVKCodes.insert(std::make_pair("f6", 0x75));
	mapOfVKCodes.insert(std::make_pair("f7", 0x76));
	mapOfVKCodes.insert(std::make_pair("f8", 0x77));
	mapOfVKCodes.insert(std::make_pair("f9", 0x78));
	mapOfVKCodes.insert(std::make_pair("f10", 0x79));
	mapOfVKCodes.insert(std::make_pair("f11", 0x7A));
	mapOfVKCodes.insert(std::make_pair("f12", 0x7B));
	mapOfVKCodes.insert(std::make_pair("f13", 0x7C));
	mapOfVKCodes.insert(std::make_pair("f14", 0x7D));
	mapOfVKCodes.insert(std::make_pair("f15", 0x7E));
	mapOfVKCodes.insert(std::make_pair("f16", 0x7F));
	mapOfVKCodes.insert(std::make_pair("f17", 0x80));
	mapOfVKCodes.insert(std::make_pair("f18", 0x81));
	mapOfVKCodes.insert(std::make_pair("f19", 0x82));
	mapOfVKCodes.insert(std::make_pair("f20", 0x83));
	mapOfVKCodes.insert(std::make_pair("f21", 0x84));
	mapOfVKCodes.insert(std::make_pair("f22", 0x85));
	mapOfVKCodes.insert(std::make_pair("f23", 0x86));
	mapOfVKCodes.insert(std::make_pair("f24", 0x87));
	mapOfVKCodes.insert(std::make_pair("numlock", 0x90));
	mapOfVKCodes.insert(std::make_pair("scrolllock", 0x91));
	mapOfVKCodes.insert(std::make_pair("leftshift", 0xA0));
	mapOfVKCodes.insert(std::make_pair("rightshift", 0xA1));
	mapOfVKCodes.insert(std::make_pair("leftcontrol", 0xA2));
	mapOfVKCodes.insert(std::make_pair("rightcontrol", 0xA3));
	mapOfVKCodes.insert(std::make_pair("leftmenu", 0xA4));
	mapOfVKCodes.insert(std::make_pair("rightmenu", 0xA5));
	mapOfVKCodes.insert(std::make_pair("volumemute", 0xAD));
	mapOfVKCodes.insert(std::make_pair("volumedown", 0xAE));
	mapOfVKCodes.insert(std::make_pair("volumeup", 0xAF));
	mapOfVKCodes.insert(std::make_pair("nexttrack", 0xB0));
	mapOfVKCodes.insert(std::make_pair("previoustrack", 0xB1));
	mapOfVKCodes.insert(std::make_pair("stop", 0xB2));
	mapOfVKCodes.insert(std::make_pair("play", 0xB3));
	mapOfVKCodes.insert(std::make_pair("pause", 0xB3));
	mapOfVKCodes.insert(std::make_pair("+", 0xBB));
	mapOfVKCodes.insert(std::make_pair(",", 0xBC));
	mapOfVKCodes.insert(std::make_pair("-", 0xBD));
	mapOfVKCodes.insert(std::make_pair(".", 0xBE));
}

Napi::String PressRelease(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	if (info.Length() == 0)
	{
		Napi::TypeError::New(env, "No argument").ThrowAsJavaScriptException();
		return Napi::String::New(env, "No argument");
	}

	if (!info[0].IsString())
	{
		Napi::TypeError::New(env, "Wrong argument").ThrowAsJavaScriptException();
		return Napi::String::New(env, "Wrong argument");
	}

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // Hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	std::map<std::string, int>::iterator it;
	it = mapOfVKCodes.find(info[0].As<Napi::String>());
	if (it != mapOfVKCodes.end())
	{
		ip.ki.wVk = it->second;
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		// Release the key
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
	}
	else
	{
		return Napi::String::New(env, "No key found");
	}

	return Napi::String::New(env, "Ok - press and release");
}
Napi::String KeyPress(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	if (info.Length() == 0)
	{
		Napi::TypeError::New(env, "No argument")
				.ThrowAsJavaScriptException();
		return Napi::String::New(env, "No argument");
	}

	if (!info[0].IsString())
	{
		Napi::TypeError::New(env, "Wrong argument").ThrowAsJavaScriptException();
		return Napi::String::New(env, "Wrong argument");
	}

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // Hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	std::map<std::string, int>::iterator it;
	it = mapOfVKCodes.find(info[0].As<Napi::String>());
	if (it != mapOfVKCodes.end())
	{
		ip.ki.wVk = it->second;
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));
	}
	else
	{
		return Napi::String::New(env, "No key found");
	}

	return Napi::String::New(env, "Ok - press");
}
Napi::String KeyRelease(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	if (info.Length() == 0)
	{
		Napi::TypeError::New(env, "No argument")
				.ThrowAsJavaScriptException();
		return Napi::String::New(env, "No argument");
	}

	if (!info[0].IsString())
	{
		Napi::TypeError::New(env, "Wrong argument").ThrowAsJavaScriptException();
		return Napi::String::New(env, "Wrong argument");
	}

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // Hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	std::map<std::string, int>::iterator it;
	it = mapOfVKCodes.find(info[0].As<Napi::String>());
	if (it != mapOfVKCodes.end())
	{
		ip.ki.wVk = it->second;
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
	}
	else
	{
		return Napi::String::New(env, "No key found");
	}

	return Napi::String::New(env, "Ok - release");
}

Napi::Value Type(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	if (info.Length() == 0)
	{
		Napi::TypeError::New(env, "No argument").ThrowAsJavaScriptException();
		return Napi::String::New(env, "No argument");
	}

	if (!info[0].IsString())
	{
		Napi::TypeError::New(env, "Wrong argument").ThrowAsJavaScriptException();
		return Napi::String::New(env, "Wrong argument");
	}

	std::string arg0 = info[0].As<Napi::String>(); // convert argument to a string

	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // Hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	std::map<std::string, int>::iterator it;

	for (int i = 0; i < arg0.length(); i++) // Walk-through the string and type
	{
		string letter(1, arg0[i]);
		// cout << typeid(arg0[i]).name() << endl;
		it = mapOfVKCodes.find(letter);
		if (it != mapOfVKCodes.end())
		{
			ip.ki.wVk = it->second;
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			// Release the key
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
		}
		else
		{
			return Napi::String::New(env, "Invalid key found");
		}
		Sleep(500); // Wait a bit before next letter
	}

	return Napi::String::New(env, "ok - typing");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
	defineKeys();
	exports.Set(Napi::String::New(env, "keyPressRelease"), Napi::Function::New(env, PressRelease));
	exports.Set(Napi::String::New(env, "keyPress"), Napi::Function::New(env, KeyPress));
	exports.Set(Napi::String::New(env, "keyRelease"), Napi::Function::New(env, KeyRelease));
	exports.Set(Napi::String::New(env, "type"), Napi::Function::New(env, Type));
	return exports;
}

NODE_API_MODULE(virtualkeycode, Init)