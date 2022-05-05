#include <iostream>
#include <vector>
#include <string>
using namespace std;
class FileSys {
protected:
	string name;
public:
	FileSys(const string &m_name):name(m_name) {}
	virtual int getSize() = 0;
	virtual void output(const int& level = 0) = 0;
	virtual vector<FileSys*>search(const string &name) = 0;
};
class File :public FileSys {
private:
	int size;
public:
	File(const string& m_name, int m_size) :FileSys(m_name), size(m_size) {}
	int getSize() {
		return size;
	}
	void output(const int& level = 0) {
		for (int i = 0; i < level; i++)
			cout << "    ";
		cout << name << "    " << size << " B" << endl;
	}
	vector<FileSys*>search(const string& name) {
		return { this };
	}
};
class Folder :public FileSys {
private:
	vector<FileSys*> files;
public:
	Folder(const string& m_name) :FileSys(m_name) {}
	void addFile(FileSys* m_files) {
		files.push_back(m_files);
	}
	int getSize() {
		int s = 0;
		for (int i = 0; i < files.size(); i++)
			s += files[i]->getSize();
		return s;
	}
	int count() {
		return files.size();
	}
	void output(const int& level = 0) {
		for (int i = 0; i < level; i++)
			cout << "    ";
		cout << "[" << name << "]" << endl;
		for (const auto& file : files)
			file->output(level + 1);
	}
	vector<FileSys*>search(const string& m_name) {
		vector<FileSys*>res;
		if (name == m_name) {
			res.push_back(this);
			for (int i = 0; i < files.size(); i++) {
				vector<FileSys*>temp = files[i]->search(m_name);
				for (int j = 0; j < temp.size(); j++)
					res.push_back(temp[j]);
			}
		}
		return res;
	}
};
int main() {
	Folder c("C:");
	Folder baitap("Bai Tap");
	File bt1doc("BT1.doc", 123456);
	Folder baiTapC("Bai tap C");
	File bt2cpp("BT2.cpp", 1280);
	File bt2xls("BT2.xls", 23456);
	Folder lyThuyet("Ly thuyet");
	File ch1("Ch1.ppt", 34567);

	c.addFile(&baitap);
	c.addFile(&lyThuyet);

	baitap.addFile(&bt1doc);
	baitap.addFile(&baiTapC);
	baitap.addFile(&bt2cpp);
	baitap.addFile(&bt2xls);


	lyThuyet.addFile(&ch1);
	c.output();
	return 0;
}