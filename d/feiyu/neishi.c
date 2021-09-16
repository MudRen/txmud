// Room: /wiz/louth/a/neishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�䲼�ü򵥵ķ��䣬�м���һ�Ű���������Χ�����
�ڷ��ż������ӣ���ǽ����һ�����ӣ������Ĵ���ɨ�øɸɾ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yaxinroom",
]));
	setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me;
        me = this_player();
        if (arg != "����" && arg != "cupboard")
                return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$N�򿪹��ӣ�������߾�Ȼ��һ���ص�����ڡ�\n",me);
        set("exits/enter", __DIR__"midao1");
	call_out("do_close",8);
        return 1;
}

void do_close()
{
	if(query("exits/enter"))
	{
		delete("exits/enter");
		tell_room(this_object(),"��������������ˡ�\n");
	}
}
