// Room: /d/path3/k_s14.c

inherit DANGER_ROAD;

void create()
{
	set("short", "����");
	set("long", @LONG
���߽�һƬ���֣�ֻ���������������ȫ�����ӣ������Ǹ�
�¹����Ե�ʣ�һЩ���Ӹ������������̵����񡣻����������
Ҷ������˵��ʲô�����Ĵ�������һ�£�ʲô��û�з��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"k_s13",
  "southwest" : __DIR__"k_s15",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
