// Room: /u/w/wangs/b/kai140.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ߵ��������������︺��������Ĵ���С�顣��
����͵��������С�������ǷŻ�ɱ�˵�ǿ���������������ܵ�Ӧ
�еĴ����������Ϸ���һ�����ң�д�š������������ĸ��̽��
�֡�һ�Ŵ󹫰���������֪�����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai138",
]));
        set("objects",([
        __DIR__"npc/zhifu": 1,
]));

	setup();
	replace_program(ROOM);
}
