//// SOCIAL_NETWORK__PROJECT
//// DISCLAMER -> ALL RIGHTS RESERVED BY OWNER______MAAZ KHAN

#include<iostream>
#include<fstream>
using namespace std;

//declaring all classes...
class User;
class Page;
class SocialNetwork;
class Helper;
class Comment;
class Date;
class Post;
class Memory;
class Object;




///CLASS_Helper.
class Helper
{
public:
	///FUNCTION FOR FINDING LENGTH OF THE STRING
	static int StringLength(const char* str)
	{
		int length = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			length++;
		}
		return length;
	}

	///FUNCTION FOR COPYING STRING
	static void StringCopy(char* dest, char* src)
	{
		int i = 0;
		for (; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}

	///FUNCTION FOR GETTING TEMP BUFFER DYNAMICALLY
	static char* GetStringFromBuffer(char* str)
	{
		char* newStr = new char[StringLength(str) + 1];
		StringCopy(newStr, str);
		return newStr;
	}

	///FUNCTION FOR FINDING SUBSTRING
	static int FindSubStr(char* subStr, char* mainStr)
	{
		bool found = false;
		int count = 0;
		int length_of_subStr = StringLength(subStr);
		int length_of_mainStr = StringLength(mainStr);

		for (int i = 0; i < length_of_mainStr; i++)
		{
			count = 0;
			if (subStr[0] == mainStr[i])
			{
				count++;
				for (int j = 1; j < length_of_subStr; j++)
				{
					if (subStr[j] == mainStr[i + 1])
					{
						count++;
						i++;
					}
					if (count == length_of_subStr)
					{
						found = true;
					}
				}
			}
		}
		if (found)
			return 1;
		else
			return 0;
	}

	///FUNCTION FOR COMPARE_STRINGS
	static int CompareString(char* ptr1, const char* ptr2)
	{
		//this function compare the strings alphabatically
		int len1 = StringLength(ptr1);
		int len2 = StringLength(ptr2);
		int lessLen = 0;

		if (len1 <= len2)
		{
			lessLen = len1;
		}
		if (len2 < len1)
		{
			lessLen = len2;
		}

		for (int i = 0; i < lessLen; i++)
		{
			if (ptr1[i] < ptr2[i])
			{
				return -1;
			}
			if (ptr1[i] > ptr2[i])
			{
				return 1;
			}
			if (ptr1[i] == ptr2[i])
			{
				continue;
			}
		}
		if (lessLen == len1 == len2)
		{
			return 0;
		}
		if (lessLen != len1)
		{        //ptr1 is remaining..
			return 1;
		}
		if (lessLen != len2)
		{        //ptr2 is remaining..
			return -1;
		}
		return 0;
	}

	///FUNCTION TO CONVERT INT TO C_STRING
	static char* IntToCstring(int num)
	{

		int no = num;
		//counting no of digits...
		int count = 0;
		while (1) {
			if (num < 10) {
				count++;
				break;
			}
			num = num / 10;
			count++;
		}

		char* str = new char[count + 1];
		int k = count - 1;
		while (1) {
			str[k] = no % 10 + '0';
			if (k == 0) {
				break;
			}
			no = no / 10;
			k--;
		}
		str[count] = '\0';

		return str;
	}
	static char* GenerateNewCommentID(const char* id_c, char* no) {

		char* str = new char[StringLength(no) + 2];
		str[0] = 'c';

		int m = 0;
		for (int i = 1; i < StringLength(no) + 1; i++) {
			str[i] = no[m];
			m++;
		}
		str[StringLength(no) + 1] = '\0';

		return str;
	}
	static char* GenerateNewPostID(const char* id_p, char* no) {

		char* str = new char[StringLength(no) + 5];


		int m = 0;
		int j = 0;
		for (int i = 0; i < StringLength(no) + 4; i++) {
			if (i < 4) {
				str[i] = id_p[j];
				j++;
			}
			if (i >= 4) {
				str[i] = no[m];
				m++;
			}
		}
		str[StringLength(no) + 4] = '\0';

		return str;
	}
	///FUNCTION FOR CONCATENATION
	static void StringConcatenate(char*& ptr1, char*& ptr2)
	{
		int lenOfStr1 = StringLength(ptr1);
		int concatinateLen = StringLength(ptr1) + StringLength(ptr2) + 2;
		char* tmpPtr = new char[lenOfStr1 + 1];

		StringCopy(tmpPtr, ptr1);
		ptr1 = new char[concatinateLen];
		int m = 0;   //iterator for 2nd string 

		//concatinating  loop..
		for (int i = 0; i < concatinateLen; i++)
		{
			if (i < lenOfStr1) {
				ptr1[i] = tmpPtr[i];
			}


			if (i >= lenOfStr1)
			{
				ptr1[i] = ptr2[m];
				m++;
			}
		}
		delete[] tmpPtr;   //dealloc...
		tmpPtr = 0;
	}
};


///____CLASS OBJECT>____
class Object
{
private:
	char* ID;
public:
	Object()
	{
		ID = 0;
	}

	char* getID()
	{
		return ID;
	}

	void setID(char* id)
	{
		ID = id;
	}

	//pure virtual function (our requirement...)
	virtual void AddPostToTimeline(Post* ptr) = 0;
	virtual void PrintNameOrTitle() = 0;
	virtual void PrintLikedBy() = 0;
	virtual void PrintAllTimeline() = 0;
	virtual void view(Object* ptr) = 0;

	virtual ~Object()
	{
		if (ID)
		{
			delete[] ID;
		}
	}
};


///____CLASS DATE____
class Date
{
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = month = year = 0;
	}

	void ReadDataFromFile(ifstream& fin)
	{
		fin >> day;
		fin >> month;
		fin >> year;
	}

	static Date CurrentDate;
	static void SetCurrentDate(int d, int m, int y)
	{
		CurrentDate.day = d;
		CurrentDate.month = m;
		CurrentDate.year = y;
	}

	int getYear() {
		return year;
	}

	bool CheckNearlyEqualDates()
	{
		if ((day == CurrentDate.day || day + 1 == CurrentDate.day) && (month == CurrentDate.month) && (year == CurrentDate.year))
			return true;

		else
			return false;
	}

	bool CheckDayAndMonthMatch()
	{
		if ((day == CurrentDate.day) && (month == CurrentDate.month))
			return true;
		else
			return false;
	}

	void PrintDifference()
	{
		int yearDiff = CurrentDate.year - year;

		cout << yearDiff << " years ago!  on this day\n";
	}

	void Print()
	{
		cout << "____" << day << "/" << month << "/" << year << endl;
	}
};
Date Date::CurrentDate;


///____CLASS COMMENT____
class Comment
{
	char* ID;
	char* text;
	Object* commentBy;
	static int totalComments;
public:
	Comment()
	{
		ID = 0;
		text = 0;
		commentBy = 0;
	}

	static void setTotalComments(int n)
	{
		totalComments = n;
	}

	static int getTotalComments()
	{
		return totalComments;
	}

	void setValues(char* id, Object* comment_by, char* txt)
	{
		ID = Helper::GetStringFromBuffer(id);
		commentBy = comment_by;
		text = Helper::GetStringFromBuffer(txt);
	}

	void print()
	{
		cout << "      ";
		if (commentBy != NULL) {
			commentBy->PrintNameOrTitle();
			cout << " wrote : " << text << "\n";
		}
	}

	~Comment()
	{
		if (ID) {
			delete[] ID;
		}
		if (text) {
			delete[] text;
		}
	}
};
int Comment::totalComments = 0;


///____CLASS ACTIVITY____
class Activity
{
	int type;
	char* value;
public:
	Activity()
	{
		type = 0;
		value = 0;
	}

	void ReadDateFromFile(ifstream& fin)
	{
		char tempBuff[50];
		fin >> type;
		fin.getline(tempBuff, 50);
		value = Helper::GetStringFromBuffer(tempBuff);
	}

	void Print()
	{
		if (type == 1) {
			cout << "is Feeling " << value << endl;
		}
		if (type == 2) {
			cout << "is Thinking about " << value << endl;
		}
		if (type == 3) {
			cout << "is Making " << value << endl;
		}
		if (type == 4) {
			cout << "Celebrating " << value << endl;
		}
	}

	~Activity()
	{
		//cout << "Activity_D called!\n";
		delete[] value;
	}
};


///____CLASS POST____
class Post
{
private:
	char* ID;
	char* text;
	Date sharedDate;
	Activity* activity;
	Object* sharedBy;
	Object** likedBy;
	Comment** post_comments;
	int choice_number;
	static int totalPosts;
	bool flag_postComments;
	bool flag_postLikedBy;
public:
	Post()
	{
		ID = 0;
		text = 0;
		activity = 0;
		sharedBy = 0;
		choice_number = 0;
		likedBy = 0;
		post_comments = 0;
		flag_postComments = true;
		flag_postLikedBy = true;
	}

	void ReadDataFromFile(ifstream& fin)
	{
		char tempBuff[100];
		int choice = 0;

		fin >> choice;
		setChoice(choice);
		fin >> tempBuff;

		ID = Helper::GetStringFromBuffer(tempBuff);

		sharedDate.ReadDataFromFile(fin);
		fin.ignore();

		fin.getline(tempBuff, 100);
		text = Helper::GetStringFromBuffer(tempBuff);

		if (choice == 2) {   //aggregation...
			activity = new Activity;
			activity->ReadDateFromFile(fin);
		}
	}

	char* getID()
	{
		return ID;
	}

	Object* getSharedBy()
	{
		return sharedBy;
	}

	int getPostedYear() {
		return sharedDate.getYear();
	}
	static int getTotalPosts()
	{
		return totalPosts;
	}

	void setSharedBy(Object* ptr)
	{
		sharedBy = ptr;
	}

	void setChoice(int n)
	{
		choice_number = n;
	}

	static void setTotalPosts(int n)
	{
		totalPosts = n;
	}

	void setLikedBy(Object* ptr)
	{
		if (flag_postLikedBy)
		{
			likedBy = new Object * [10];
			for (int i = 0; i < 10; i++)
			{
				likedBy[i] = 0;
			}
			flag_postLikedBy = false;
		}
		for (int i = 0; i < 10; i++)
		{
			if (likedBy[i] == 0)
			{
				likedBy[i] = ptr;
				break;
			}
		}
	}

	void setValues(char* id, char* txt, Object* sharedBy_obj, int choice)
	{
		ID = Helper::GetStringFromBuffer(id);
		text = Helper::GetStringFromBuffer(txt);
		sharedBy = sharedBy_obj;
		choice_number = choice;
		sharedDate = Date::CurrentDate;
	}

	void checkDatesNearByMatch()
	{
		if (sharedDate.CheckNearlyEqualDates() == true)
		{
			bool flag_datePrint = false;
			print(flag_datePrint);
		}
	}

	void checkDateMatchForMemories()
	{
		if (sharedDate.CheckDayAndMonthMatch() == true)
		{
			sharedDate.PrintDifference();
			print();
		}
	}



	void AddComment(Comment* ptr)
	{
		if (flag_postComments) {
			post_comments = new Comment * [10];
			for (int i = 0; i < 10; i++)
			{
				post_comments[i] = 0;
			}
			flag_postComments = false;
		}
		for (int i = 0; i < 10; i++)
		{
			if (post_comments[i] == 0)
			{
				post_comments[i] = ptr;
				break;
			}
		}
	}

	void ViewLikedList()
	{
		cout << "Post likedBy :-\n";
		if (likedBy) {
			for (int i = 0; i < 10; i++)
			{
				if (likedBy[i] == 0)
				{
					break;
				}
				else
				{
					likedBy[i]->PrintLikedBy();
				}
			}
		}
	}

	void LikePost(Object* ptr)
	{

		for (int i = 0; i < 10; i++)
		{
			if (likedBy[i] == 0)
			{
				likedBy[i] = ptr;
				break;
			}
		}
	}

	void PostComment(char* comment_text, Object* commentBy)
	{
		Comment* ourComment = new Comment;

		int num = Comment::getTotalComments() + 1;
		Comment::setTotalComments(num);

		const char* id_c = "c";
		char* id_no = Helper::IntToCstring(num);
		char* comment_id = Helper::GenerateNewCommentID(id_c, id_no);

		ourComment->setValues(comment_id, commentBy, comment_text);

		AddComment(ourComment);
		delete[] comment_id;
		delete[] id_no;
	}

	void MemoryTextPrint() {
		cout << " ''" << text << "''___";
		sharedDate.Print();
		cout << "\n";
	}


	virtual void print(bool flag_datePrint = true)    //should be virtual function to work with both memory and post....
	{
		if (choice_number == 1)
		{
			sharedBy->PrintNameOrTitle();
			cout << "shared  ''" << text << "''";
			if (flag_datePrint)
			{
				sharedDate.Print();
			}
			cout << "\n";
			if (post_comments) {
				for (int i = 0; i < 10; i++)
				{
					if (post_comments[i] == 0)
					{
						break;
					}
					else
					{
						post_comments[i]->print();
					}
				}
				cout << endl << endl;
			}
		}
		if (choice_number == 2)
		{
			sharedBy->PrintNameOrTitle();
			activity->Print();
			cout << endl;
			cout << "  ''" << text << "''";
			if (flag_datePrint)
			{
				sharedDate.Print();
			}
			cout << "\n ";
			if (post_comments) {
				for (int i = 0; i < 10; i++)
				{
					if (post_comments[i] == 0)
					{
						break;
					}
					else
					{
						post_comments[i]->print();
					}
				}

				cout << endl << endl;
			}
		}
	}

	virtual ~Post()
	{
		if (ID)
			delete[] ID;
		if (text)
			delete[] text;
		if (activity)
			delete activity;
		if (likedBy)
			delete[] likedBy;
		if (post_comments)
		{
			for (int i = 0; i < 10; i++)
			{
				if (post_comments[i] != 0)
				{
					delete post_comments[i];
				}
				if (post_comments[i] == 0)
				{
					break;
				}
			}
			delete[] post_comments;
		}
	}
};
int Post::totalPosts = 0;   //public posts count


///   ____CLASS PAGE____
class Page : public Object
{
private:
	char* Title;
	Post** timeline;
public:
	Page()
	{
		Title = 0;
		timeline = new Post * [10];
		for (int i = 0; i < 10; i++) {
			timeline[i] = 0;
		}
	}

	void ReadDataFromFile(ifstream& fin)
	{
		char tempBuff[50];

		fin >> tempBuff;
		char* id = Helper::GetStringFromBuffer(tempBuff);
		setID(id);

		fin.getline(tempBuff, 50);
		Title = Helper::GetStringFromBuffer(tempBuff);
	}

	char* getID()
	{
		return Object::getID();
	}

	void PrintNameOrTitle()
	{
		cout << Title << " ";
	}

	void PrintListView()
	{
		cout << "  " << Title << "\n";
	}

	void AddPostToTimeline(Post* ptr)
	{
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] == 0)
			{
				timeline[i] = ptr;
				break;
			}
		}
	}

	void PrintLatestPosts()
	{
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] == 0)
			{
				break;
			}
			else
			{
				timeline[i]->checkDatesNearByMatch();
			}
		}
	}

	void PrintAllTimeline()
	{
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] == 0)
			{
				break;
			}
			else
			{
				timeline[i]->print();
			}
		}
	}

	void PrintLikedBy()
	{
		cout << getID();
		cout << "    " << Title << "\n";
	}

	void view(Object* ptr)
	{
		ptr->PrintAllTimeline();
	}

	~Page()
	{

		//cout << "call for P_destructor!\n";

		if (Title)
			delete[] Title;
		if (timeline)
		{
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] != 0)
				{
					delete timeline[i];
				}
			}
			delete[] timeline;
		}
	}
};


///____CLASS MEMORY____
class Memory : public Post
{
	Post* orignalPost;
public:

	Memory()
	{
		orignalPost = 0;
	}

	Memory(Post* ptr) {
		orignalPost = ptr;
	}

	void setMemory(char* id, char* txt, Object* shareBy, int choicePrint)
	{
		Post::setValues(id, txt, shareBy, choicePrint);
	}

	void print(bool flag_datePrint = true)
	{
		cout << "\n";
		Object* ptr = getSharedBy();
		ptr->PrintNameOrTitle();
		cout << "shared a memory ";
		Post::MemoryTextPrint();

		int orignalPostYear = orignalPost->getPostedYear();
		int n = getPostedYear() - orignalPostYear;
		cout << "\n\n                              " << n << " years ago!\n\n";

		orignalPost->print();
	}
};


///   ____CLASS USER____
class User : public Object
{
private:

	char* Fname;
	char* Lname;
	Page** LikedPages;
	User** FriendList;
	Post** timeline;
	bool flag_friend;
	bool flag_like;
	bool flag_timeline;

public:
	User()
	{
		Fname = Lname = 0;
		LikedPages = 0;
		FriendList = 0;
		timeline = 0;
		flag_friend = true;
		flag_like = true;
		flag_timeline = true;

	}

	void ReadDataFromFile(ifstream& fin)
	{
		char tempBuff[100];
		fin >> tempBuff;
		char* id = Helper::GetStringFromBuffer(tempBuff);
		setID(id);
		fin >> tempBuff;
		Fname = Helper::GetStringFromBuffer(tempBuff);

		fin >> tempBuff;
		Lname = Helper::GetStringFromBuffer(tempBuff);

	}

	char* getID()
	{
		return Object::getID();
	}

	void PrintNameOrTitle()
	{
		cout << Fname << " " << Lname << " ";
	}

	void PrintLatestPosts()
	{
		if (timeline) {
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] == 0)
				{
					break;
				}
				else
				{
					timeline[i]->checkDatesNearByMatch();
				}
			}
		}
	}

	void LikePage(Page* ptr)
	{
		if (flag_like)
		{
			LikedPages = new Page * [10];
			for (int i = 0; i < 10; i++)
			{
				LikedPages[i] = 0;
			}
			flag_like = false;
		}
		for (int i = 0; i < 10; i++)
		{
			if (LikedPages[i] == 0)
			{
				LikedPages[i] = ptr;
				break;
			}
		}
	}

	void AddFriend(User* ptr)
	{

		if (flag_friend)
		{     //intiniallization....
			FriendList = new User * [10];
			for (int i = 0; i < 10; i++)
			{
				FriendList[i] = 0;
			}
			flag_friend = false;
		}


		for (int i = 0; i < 10; i++)
		{
			if (FriendList[i] == 0)
			{
				FriendList[i] = ptr;
				break;
			}
		}
	}

	void AddPostToTimeline(Post* ptr)
	{
		if (flag_timeline)
		{
			timeline = new Post * [10];
			for (int i = 0; i < 10; i++)
			{
				timeline[i] = 0;
			}
			flag_timeline = false;
		}
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] == 0)
			{
				timeline[i] = ptr;
				break;
			}
		}
	}

	void ViewFriendList()
	{
		int i = 0;
		if (FriendList) {
			while (FriendList[i] != 0)
			{
				FriendList[i]->PrintListView();
				i++;
			}
		}
		else
			cout << "No Friend found in friend list\n";
	}

	void ViewLikedPages()
	{
		int i = 0;
		if (LikedPages) {
			while (LikedPages[i] != 0)
			{
				LikedPages[i]->PrintListView();
				i++;
			}
		}
		else
			cout << "No Pages Found in LikedPages List!\n";
	}

	void ViewHome()
	{
		if (FriendList) {
			for (int i = 0; i < 10; i++)
			{
				if (FriendList[i] == 0)
				{
					break;
				}
				else {
					FriendList[i]->PrintLatestPosts();
				}

			}
		}
		if (LikedPages)
		{

			for (int i = 0; i < 10; i++)
			{
				if (LikedPages[i] == 0)
				{
					break;
				}
				else
				{
					LikedPages[i]->PrintLatestPosts();
				}

			}
		}
	}

	void ViewTimeline()
	{
		if (timeline) {
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] == 0)
				{
					break;
				}
				else
				{
					timeline[i]->print();
				}
			}
		}
		else {
			cout << "no posts found in timeline section!\n";
		}
	}

	void PrintListView()
	{
		cout << getID();
		cout << "   " << Fname << " " << Lname << "\n";
	}



	void PrintLikedBy()
	{
		cout << getID();
		cout << "    " << Fname << " " << Lname << "\n";
	}

	void seeMemories()
	{
		if (timeline) {
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] == 0)
				{
					break;
				}
				else
				{
					timeline[i]->checkDateMatchForMemories();
				}
			}
		}
		else
			cout << "no previous posts Data found!\n";

	}

	void ShareMemory(Post* orgPostPtr, char* txt, Object* sharedByObj) {
		Memory* newMemory = new Memory(orgPostPtr);

		int num = Post::getTotalPosts() + 1;
		Post::setTotalPosts(num);

		const char* id_p = "post";
		char* id_no = Helper::IntToCstring(num);
		char* post_id = Helper::GenerateNewPostID(id_p, id_no);

		newMemory->setValues(post_id, txt, sharedByObj, 3);
		AddPostToTimeline(newMemory);
		newMemory->print();

		delete[] post_id;
		delete[] id_no;
	}

	void PrintAllTimeline()
	{
		for (int i = 0; i < 10; i++)
		{
			if (timeline[i] == 0)
			{
				break;
			}
			else
			{
				timeline[i]->print();
			}
		}
	}

	void view(Object* ptr)
	{
		ptr->PrintAllTimeline();
	}

	~User()
	{
		//cout << "call for U_destructor!\n";

		if (Fname)
			delete[] Fname;
		if (Lname)
			delete[] Lname;
		if (FriendList)
			delete[] FriendList;
		if (LikedPages)
			delete[] LikedPages;
		if (timeline)
		{
			for (int i = 0; i < 10; i++)
			{
				if (timeline[i] != 0)
				{
					delete timeline[i];
				}
			}
			delete[] timeline;
		}
	}

};


///   ____CLASS SOCIALNETWORK____
class SocialNetwork {
private:
	Page** pages;
	User** users;
	Post** posts;
	static int totalPagesCount;
	static int totalUsersCount;
	static int totalPostsCount;
	static int totalCommentsCount;
public:
	SocialNetwork() {
		pages = 0;
		users = 0;
		posts = 0;
	}

	static int getTotalNumberOfComments() {
		return totalCommentsCount;
	}

	Object* searchObjectByID(const char* ptr) {

		if (ptr[0] == 'u')
		{
			return searchUserByID(ptr);
		}
		if (ptr[0] == 'p')
		{
			return  searchPageByID(ptr);
		}
		return 0;
	}

	Post* searchPostByID(const char* ptr) {

		for (int i = 0; i < totalPostsCount; i++) {
			if (Helper::CompareString(posts[i]->getID(), ptr) == 0) {
				return posts[i];
			}
		}
		return 0;
	}

	Page* searchPageByID(const char* ptr) {

		for (int i = 0; i < totalPagesCount; i++) {
			if (Helper::CompareString(pages[i]->getID(), ptr) == 0) {
				return pages[i];
			}
		}
		return 0;
	}

	User* searchUserByID(const char* ptr)
	{
		for (int i = 0; i < totalUsersCount; i++)
		{
			if (Helper::CompareString(users[i]->getID(), ptr) == 0)
			{
				return users[i];
			}
		}
		return 0;
	}

	void LoadPagesFromFile(const char* filename)
	{
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{
			cout << "--------------------------------------------------------------------\n";
			cout << "Pages file opened successfully!\n";
			int totalPages = 0;
			fin >> totalPages;  //total = 12
			totalPagesCount = totalPages;

			pages = new Page * [totalPagesCount];
			for (int i = 0; i < totalPagesCount; i++)
			{
				pages[i] = new Page;
				pages[i]->ReadDataFromFile(fin);
			}
			fin.close();
		}
		else
			cout << "file not opened successfully!\n";


	}

	void LoadUsersFromFile(const char* filename)
	{
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{

			cout << "Users file opened successfully!";
			cout << "\n--------------------------------------------------------------------\n";
			int totalUsers = 0;
			fin >> totalUsers; //total = 20
			totalUsersCount = totalUsers;

			////initialization of char triple pointer....
			char*** tempFriendList = new char** [totalUsersCount];
			for (int i = 0; i < totalUsersCount; i++)
			{
				tempFriendList[i] = new char* [10];
			}


			users = new User * [totalUsersCount];
			for (int i = 0; i < totalUsersCount; i++)
			{
				users[i] = new User;
				users[i]->ReadDataFromFile(fin);
				char temp[20];

				//for friend ID's

				int k = 0;
				while (true)
				{
					fin >> temp;
					if (Helper::CompareString(temp, "-1") != 0)
					{
						tempFriendList[i][k] = Helper::GetStringFromBuffer(temp);
						k++;
					}
					else
					{
						tempFriendList[i][k] = NULL;
						break;
					}
				}



				//for pages ID's ....
				fin >> temp;
				while (Helper::CompareString(temp, "-1") != 0)
				{
					Page* ptr = searchPageByID(temp);
					users[i]->LikePage(ptr);
					fin >> temp;
				}

			}

			int index = 0;
			int i = 0;
			while (i < totalUsersCount)
			{

				while (tempFriendList[i][index] != NULL)
				{
					User* ptr = searchUserByID(tempFriendList[i][index]);
					users[i]->AddFriend(ptr);
					delete[] tempFriendList[i][index];
					if (index != 10) {
						index++;
					}
				}
				delete[] tempFriendList[i];
				if (i < totalUsersCount)
				{
					i++;
				}
				index = 0;
			}
			delete[] tempFriendList;


			fin.close();
		}
		else
			cout << "file not opened successfully!\n";
	}

	void LoadPostsFromFile(const char* filename)
	{
		ifstream fin;
		fin.open(filename);
		if (!fin)
		{
			cout << "file not opened successfully!\n";
		}
		else
		{
			cout << "\n--------------------------------------------------------------------\n";
			cout << "Posts file opened successfully!\n";
			int totalPosts = 0;
			fin >> totalPosts; //total = 20
			totalPostsCount = totalPosts;
			Post::setTotalPosts(totalPostsCount);

			posts = new Post * [totalPostsCount];
			for (int i = 0; i < totalPostsCount; i++)
			{
				posts[i] = new Post;
				posts[i]->ReadDataFromFile(fin);
				char temp[10];
				fin >> temp;
				Object* sharedBy = searchObjectByID(temp);
				posts[i]->setSharedBy(sharedBy);
				sharedBy->AddPostToTimeline(posts[i]);

				while (true)
				{
					fin >> temp;
					if (Helper::CompareString(temp, "-1") == 0)
					{
						break;
					}
					Object* likedBy = searchObjectByID(temp);
					posts[i]->setLikedBy(likedBy);

				}
			}


			fin.close();
		}
	}

	void LoadCommentsFromFile(const char* filename)
	{
		ifstream fin;
		fin.open(filename);
		if (!fin)
		{
			cout << "Comments file not opened successfully!\n";
		}
		else
		{

			cout << "Comments file opened successfully!";
			cout << "\n--------------------------------------------------------------------\n";
			int totalComments = 0;
			fin >> totalComments; //total = 20
			totalCommentsCount = totalComments;
			Comment::setTotalComments(totalCommentsCount);

			for (int i = 0; i < totalCommentsCount; i++)
			{
				Comment* comment = new Comment;
				char tempBuff[100];
				char* id = 0;
				char post_id[20];
				char* text = 0;

				fin >> tempBuff;
				id = Helper::GetStringFromBuffer(tempBuff);

				fin >> post_id;
				Post* postPtr = searchPostByID(post_id);
				postPtr->AddComment(comment);

				fin >> tempBuff;
				Object* commentBy = searchObjectByID(tempBuff);

				fin.getline(tempBuff, 100);
				text = Helper::GetStringFromBuffer(tempBuff);

				comment->setValues(id, commentBy, text);
				if (text)
					delete[] text;
				if (id)
					delete[] id;
			}
			fin.close();
		}
	}

	void Load()
	{
		LoadPagesFromFile("SocialNetworkPages.txt");
		LoadUsersFromFile("SocialNetworkUsers.txt");
		LoadPostsFromFile("SocialNetworkPosts.txt");
		LoadCommentsFromFile("SocialNetworkComments.txt");
	}

	void Execute()
	{
		bool execute_flag = true;

		//setting current date...
		int curr_Day = 15;
		int curr_Month = 11;
		int curr_Year = 2017;
		Date::SetCurrentDate(curr_Day, curr_Month, curr_Year);

		//setting current user...
		char ourUser[10] = "u7";
		User* currUser = searchUserByID(ourUser);

		if (!currUser)
		{
			cout << "User " << ourUser << " not found in our database!\n\n";
			execute_flag = false;
		}

		if (execute_flag) {
			cout << ourUser << " set as current user successfully!.....\n";
			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : FriendList \n\n";
			currUser->ViewFriendList();
			cout << "\n--------------------------------------------------------------------\n";


			cout << "\nCommand : LikedPages \n\n";
			currUser->ViewLikedPages();

			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : ViewHome \n\n";
			currUser->ViewHome();

			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : ViewTimeline \n\n";
			currUser->ViewTimeline();

			cout << "\n--------------------------------------------------------------------\n";

			char ourPost[10] = "post5";
			Post* currPost = searchPostByID(ourPost);

			if (!currPost) {
				cout << " no post found having id " << ourPost << "\n";
			}
			if (currPost) {
				cout << "\nCommand : ViewLikedList \n\n";
				currPost->ViewLikedList();

				cout << "\n--------------------------------------------------------------------\n";

				cout << "\nCommand : LikePost (post5) \n\n";
				currPost->LikePost(currUser);

				cout << "\n--------------------------------------------------------------------\n";

				cout << "\nCommand : ViewLikedList \n\n";
				currPost->ViewLikedList();
			}
			cout << "\n--------------------------------------------------------------------\n";


			cout << "\nCommand : PostComment \n\n";
			char postForCommentID_1[10] = "post4";
			Post* postForCommentPtr_1 = searchPostByID(postForCommentID_1);
			char temp_1[] = "How was the result brother?";
			if (!postForCommentPtr_1) {
				cout << " no post found having id " << postForCommentID_1 << "\n";
			}






			if (postForCommentPtr_1)
			{
				postForCommentPtr_1->PostComment(temp_1, currUser);

				cout << "\n--------------------------------------------------------------------\n";

				cout << "\nCommand : ViewPost  \n\n";
				postForCommentPtr_1->print();
			}

			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : PostComment \n\n";
			char postForCommentID_2[10] = "post8";
			Post* postForCommentPtr_2 = searchPostByID(postForCommentID_2);
			char temp_2[] = "Thanks for the wishes";

			if (!postForCommentPtr_2) {
				cout << " no post found having id " << postForCommentID_2 << "\n";
			}
			if (postForCommentPtr_2) {
				postForCommentPtr_2->PostComment(temp_2, currUser);

				cout << "\n--------------------------------------------------------------------\n";

				cout << "\nCommand : ViewPost  \n\n";
				postForCommentPtr_2->print();
			}
			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : ObjectFaceView (pX) or (uX) \n\n";
			char objID[10] = "p1";
			Object* ObjPtr = searchObjectByID(objID);
			if (!ObjPtr) {
				cout << " no Obj found having id " << objID << "\n";
			}
			if (ObjPtr) {
				ObjPtr->view(ObjPtr);
			}

			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : SeeYourMemories  \n\n";
			currUser->seeMemories();

			cout << "\n--------------------------------------------------------------------\n";

			cout << "\nCommand : ShareMemory  \n\n";
			char memoryText[] = "Never thought I will be specialist in this field";
			Post* MemoryOrgPostID = searchPostByID("post10");
			currUser->ShareMemory(MemoryOrgPostID, memoryText, currUser);

			cout << "\n--------------------------------------------------------------------\n";


			cout << "\nCommand : ViewTimeline \n\n";

			currUser->ViewTimeline();

			cout << "\n--------------------------------------------------------------------\n";
		}
	}
	~SocialNetwork() {
		for (int i = 0; i < totalPagesCount; i++)
		{
			delete pages[i];
		}
		delete[] pages;

		for (int i = 0; i < totalUsersCount; i++)
		{
			delete users[i];
		}
		delete[] users;

		if (posts)
			delete[] posts;
	}
};
int SocialNetwork::totalPagesCount = 0;
int SocialNetwork::totalUsersCount = 0;
int SocialNetwork::totalPostsCount = 0;
int SocialNetwork::totalCommentsCount = 0;


/// ____PROGRAM MAIN()____
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);    //checker for detecting memory leakages....

	try
	{
		SocialNetwork controller;
		controller.Load();
		controller.Execute();
	}
	                                                                            
	catch (exception& ex)
	{
		cerr << "SOMETHING WENT WRONG :(                      ~(ERROR 404)\n" << ex.what() << endl;
	}


	//for executing the program uncomment the following line it is commented out to see the memory leakage in the program
	system("pause");
	return 0;
}
