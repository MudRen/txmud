// jiulou  ��������¥

inherit ROOM;
inherit SHOW_MSG;

void create()
{
        set("short", "����¥");
        set("long", @LONG
�����ǳ�������¥�������ڳ��������������ĵ���̩·�ߣ�
�ǳ�����������һ�Ҵ��¥����˵��Ҿ�¥���ϰټҵ���ʷ����
��ĳ�ʦ���Ǹ��ص�����������ʲô��ɫ�˶����գ���ʱ������
�ľ���ϲ��������󱥿ڸ���һЩ������ˣ����ӣ��۹��Ҳ��
��������Լ�����Ĳ��ȡ����õ�С�����������˾��Ͳˣ��к�
���ˣ�¥����������
LONG
        );

        set("night_long", @LONG
�����ǳ�������¥���ǳ�����������һ�Ҵ��¥����������
��Զ����������˵��Ҿ�¥���ϰټҵ���ʷ�������Ѿ������ˣ�
���õ�û����ɵ�ſ�ڹ�̨�ϡ�
LONG
        );

	set("exits", ([
		"west" : __DIR__"wroad1",
		"up" : __DIR__"jiulou2",
		"east" : __DIR__"chufang",
]));

	set_master("pao tang");

	set(SAFE_ENV, 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));

        setup();
        load_board("board_changan");
}
/*
void init()
{
	add_action("do_help","help");
}

int do_help(string arg)
{
	if( (arg == "new") && this_player() )
		this_player()->delete_temp("I_AM_NEWBIE");
	return 0;
}

int valid_leave(object me,string dir)
{
	if(me->query_temp("I_AM_NEWBIE"))
		return notify_fail("С���ó���Ц��˵���������ȿ��� help new���ǿɶ����������Ʒ��\n");

	return ::valid_leave(me,dir);
}
*/

