// Room: /wiz/louth/c/mianguan.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����ǳɶ���һ����ݣ���Ȼ���治�󣬵��Ƿ���ȴ�ǳ���
��������������һ�źܴ�İ���������ΧһȦ�������ˣ�����
�ǻ���̸Ц��������ʱ�򻹻������Ц�����������������߾���
����·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu7",
]));
        set("objects",([
        __DIR__"npc/liboss" : 1,
]));


	setup();
	replace_program(ROOM);
}
