// Room: /d/path3/k_s12.c

inherit DANGER_ROAD;

void create()
{
	set("short", "С����");
	set("long", @LONG
���߽�һƬ���֣�ֻ���������������ȫ�����ӣ������Ǹ�
�¹����Ե�ʣ�һЩ���Ӹ������������̵����񡣻����������
Ҷ������˵��ʲô�����Ĵ�������һ�£�ʲô��û�з��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s13",
  "north" : __DIR__"k_s11",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
