// Room: siguoya2.c

inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short","���");
	set("long",@LONG
���������彻�ᴦ���ӱ����Х������ɽ�������ﱻ��ɽ��
���˼�ʮ�׿����ڴ���������ľ���(juebi)һ������ͷһת��
������к���������з�ɳ��ʯ֮�ơ�����½󱻷紵���������졣
һ��������ӭ�������ϡ���֦��ھ�һ��������
LONG
);

	set("exits", ([ /* sizeof() == 3 */
	"west":__DIR__"siguoya.c",
]));

	set("item_desc",([
   		"����":("
	����һ����������֦Ҷϡ�裬ȴ����Ϊ��������ҡ��\n
	�㲻����˼�������ƣ�������ա��������١�\n"),

		"juebi":("
	 ɽ·������һ�½�ǧ�߸ߵľ��ڡ�����ֱ�ζ����ݲ�����\n
	 ���������������\n"),
]));

	set("outdoors", "huashan_zx");
	setup();
}

void init()
{
	add_action( (: do_enter :), ({"pa", "climb"}) );
}

int do_enter(string arg)
{
	object me = this_player();

        if( (arg != "����") && (arg != "������") )
		return notify_fail("��Ҫ��ʲô�ط�����\n");

	if( me->query_temp("on_rided") )
		UNRIDE_CMD->main(me);

	me->start_busy(1);

	message_vision("$N����������������ȥ.\n", me);

	if( me->move(__DIR__"laosong") )
		tell_room(environment(me), me->name() + "����������������\n",({me}));
	return 1;
}
