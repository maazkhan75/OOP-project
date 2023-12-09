//#include<iostream>
//using namespace std;
//int main() {
//	char str[5];
//	int num = 12345;
//
//	//counting no of digits...
//	int count = 0;
//	while (1) {
//		if (num < 10) {
//			count++;
//			break;
//		}
//		num = num / 10;
//		count++;
//	}
//	cout << count;
//
//
//
//
//
//
//
//
//
//	//actual procedure required...
//	/*int count = 0;
//	while (1)
//	{
//		if (num<10) {
//			count++;
//			cout << num;
//			break;
//		}
//		int last_digit = num % 10;
//		count++;
//		cout << last_digit << endl;
//		num = num / 10;
//	}*/
//
//
//	system("pause");
//	return 0;
//}
//
//
////int a = 1;
////char arr[1];
////arr[0] = a + '0';
////cout << arr[0];
//
//
//
//
//
//
//
//
//
//
//
//
//
////
////
////class Helper {
////public:
////	///FUNCTION FOR COMPARE_STRINGS
////	static int CompareString(string ptr1, string ptr2)
////	{
////		//this function compare the strings alphabatically
////		int len1 = ptr1.length();     //strlen func is for c-strings and .length() is for strings in c++
////		int len2 = ptr1.length();
////		int lessLen = 0;
////
////		if (len1 <= len2)
////		{
////			lessLen = len1;
////		}
////		if (len2 < len1)
////		{
////			lessLen = len2;
////		}
////
////		for (int i = 0; i < lessLen; i++)
////		{
////			if (ptr1[i] < ptr2[i])
////			{
////				return -1;
////			}
////			if (ptr1[i] > ptr2[i])
////			{
////				return 1;
////			}
////			if (ptr1[i] == ptr2[i])
////			{
////				continue;
////			}
////		}
////		if (lessLen == len1 == len2)
////		{
////			return 0;
////		}
////		if (lessLen != len1)
////		{        //ptr1 is remaining..
////			return 1;
////		}
////		if (lessLen != len2)
////		{        //ptr2 is remaining..
////			return -1;
////		}
////		return 0;
////	}
////};