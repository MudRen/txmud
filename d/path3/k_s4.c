// Room: /d/path3/k_s4.c

inherit ROOM;

void create()
{
	set("short", "פ���");
	set("long", @LONG
������פ��꣬����������ͨ��������Ъ�š�·�������һ
��С�͵꣬�������ڻ�û�п�ҵ���ڵ�·�Ķ������������һ��
����(pai)��
LONG
	);
        set("item_desc",([
	"pai":"
	north        ���⸮
	south        ����կ
	southeast    ͭ��
\n",
	"����":"
	north        ���⸮
	south        ����կ
	southeast    ͭ��
\n",
]));

	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"cross1",
  "south" : __DIR__"k_s5",
  "north" : __DIR__"k_s3",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
