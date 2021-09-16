// Room: /d/huashan/xiaolu8.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ����խ��ɽ��С·��һ����ɽ�£�һ��������Բ�
���񣬾��п��ܵ���ɽȥ�����Ʋ�ʱ�������Ư�����㲻���е�
��Щ���ˡ����ߴ�����һ�شؾ���(jingji)������һ���󻩻���
���졣
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"xiaolu9",
  "southdown" : __DIR__"xiaolu7",
]));

	set("item_desc", ([
	"jingji" : "�����ھ���������һ��С·�����ƺ������ƿ�(push)������\n",
]));

	set("outdoors", "huashan");
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!arg || (arg != "jingji" && arg != "����")) 
		return 0;

	if(undefinedp(query("exits/westup")))
	{
		set("exits/westup",__DIR__"huapo");
		message_vision("$N�ο��˾�����������һ��������·��\n",me);
		call_out("do_close",10);
	}

	else
		message_vision("$N�ζ��ž�����������ɳɳ�����졣\n",me);
	return 1;
}

void do_close()
{
	if(!undefinedp(query("exits/westup")))
	{
		tell_room(__FILE__,"һ��ɽ�紵����������·��������û�ˡ�\n");
		delete("exits/westup");
	}
}
