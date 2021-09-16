// Room: /d/guozijian/dianzhong.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��Ӻ����");
	set("long", @LONG
�ڱ�Ӻ������ģ���һ��Բ�θ�̨���������һ�������κ�
һ����ͷ����Բ̨�����ܣ����ź�ɫ�ĵ�̺��ÿ��һ�ξ���Ͱ�
һ��԰�档���ں�����д�š��ź����֡������������Ԫ��լ
���ȣ����������󱸣����������м䣬�ܾ���ѧ�ſ�ѭ����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"by_east",
		"south" : __DIR__"biyong",
		"west"  : __DIR__"by_west",
		"north" : __DIR__"by_north",
]));

	setup();
}

void init()
{
	add_action("do_walk", "walk");
}

void check_trigger()
{
	if( (int)query("x_trigger")==3
	&&	(int)query("y_trigger")==-2)
	{
		message_vision("�ذ��Ȼ����������������$Nһ�����������ȥ��\n",
			this_player() );
		this_player()->move(__DIR__"mishi");
		delete("x_trigger");
		delete("y_trigger");
	}
}

int do_walk(string arg)
{
	string dir;
	int num;
	string cdir;
	if( !arg || arg=="" ) {
		message_vision("$N����Բ�θ�̨�������ܿ��˿��������ڼ�����ʲô��\n",this_player());
		set("x_trigger",0);
		set("y_trigger",0);
		return 1;
	}
	if( sscanf(arg, "%s %d", dir,num)==2 ) {
		switch(dir) {
		    case "east" :
			cdir = "��";
			add("x_trigger", num);
			break;
		    case "south" :
			cdir = "��";
			add("y_trigger", num);
			break;
		    case "west" :
			cdir = "��";
			add("x_trigger", -1*num);
			break;
		    case "north" :
			cdir = "��";
			add("y_trigger", -1*num);
			break;
		    default :
			return notify_fail("��Ҫ�������߰���");
		}
		
		message_vision("$N��"+cdir+"����"+chinese_number(num)+"����\n", this_player());
		check_trigger();
		return 1;
	}
}


void reset()
{
	::reset();
	delete("x_trigger");
	delete("y_trigger");
}
