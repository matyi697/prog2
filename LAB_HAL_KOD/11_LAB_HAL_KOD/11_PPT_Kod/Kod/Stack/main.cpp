int main(int argc, char* argv[]) {
 
	Stack<int> s1(100);
	s1.push(10);
	s1.push(20);
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
 
	Stack<int>  s2(s1);
	s1 = s2;
 
 
	getchar();
	return 0;
 
}
