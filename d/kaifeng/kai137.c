// Room: /u/w/wangs/b/kai137.c

inherit ROOM;

void create()
{
	set("short", "���Ľ�");
	set("long", @LONG
���Ľ��ǿ��⸮����ĵ��򣬽ֵ�һ�����������Ĺ㳡��
��һ�������������ӿ�볱�����ǵ�����䣬��������������
������磬����С�ԡ�̯����������ڴˣ�ʵΪ����һ���쾰��
���Ե������ְ��������Ľֽ��������Χ������
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai96",
  "north" : __DIR__"kai76",
  "west" : __DIR__"kai74",
  "east" : __DIR__"kai138",
]));
        set("objects",([
        NPC_DIR"xunpu": 3,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
