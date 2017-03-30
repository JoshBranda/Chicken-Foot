#ifndef MY_ENDS
#define MY_ENDS

class end {
	public:
		end();
		~end();
		

	private:
		int		data;
		end *	left;
		end * 	right;

		friend class BST_ends;
};



#endif
