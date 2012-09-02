#include "..\shared_include.h"
class SecureFileBuilder
{
public:
	void set_file_path(const std::string & file_path){file_path_ = file_path;}
	void set_password(const std::string & password){password_ = password;}
	void set_company(const std::string & company){company_ = company;}

	bool Begin(){return true;}
	bool Encrypt(){ return true;}
	bool End(){return true;}

private:
	std::string file_path_;
	std::string password_;
	std::string company_;
};

int main()
{
	SecureFileBuilder builder;
	builder.set_file_path("c:\\1.txt");
	builder.set_password("123456");
	builder.set_company("everettjf");

	builder.Begin();
	builder.Encrypt();
	builder.End();

	// build complete

	return 0;
}