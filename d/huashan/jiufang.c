// Room: /d/huashan/jiufang.c

inherit ROOM;

void create()
{
	set("short", "��Ʒ�");
	set("long", @LONG
������ǻ�ɽ�ɵ���Ʒ�����ɽ����ġ������㡱��Զ����
���ĺþơ����ԭ�ǻ�ɽ�ɵĵ�һ�����룬����������������
��ɽ���ġ���ɽ�������ִ����ͷ����������������õ�����
������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shanquan",
 
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
