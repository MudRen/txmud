// Room: sg_dong2.c

inherit ROOM;

void create()
{
        set("short", "��֪��ɽ��");
        set("long", @LONG
��Ӷ���һֱ���»�����Ϊ����б�ģ�����������޷�ͣ��
����һ�ᣬ������һ�գ�������һ�Ÿɲ��ϡ�����һ����Ȼ��ɽ
�������ﵹҲ��ˬ��������������һЩ�ɲݡ����ڱ�����֦����
��͸������΢�⡣
LONG
);
	set("objects", ([
            __DIR__"master/master-feng":1,
]));

	set("item_desc",([
	"��֦" : "��֦�ִ������֦��ס�˶��ڣ�ץ(hold)����Ҳ�����������¡�\n"
]));
	setup();
}

void init()
{
	add_action("do_out","hold");
}

int do_out(string arg)
{
	object me = this_player();

	if(arg != "��֦")
		return notify_fail("��Ҫץסʲô��\n");

	message_vision("$N����������֦�������˳�ȥ��\n", me);

	if( me->move(__DIR__"laosong") )
		tell_room(environment(me), me->name() + "����������������\n",({me}));
	return 1;
}

