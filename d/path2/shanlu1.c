// Room: /d/path2/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ����᫵�ɽ·��·�����Գ����˹�ľ�ԣ�ǰ��һ�õ�
�µĺ���·�У���ס����ɽ�ĵ�·��
LONG
	);
	set("exits", ([
//	"southeast":"/d/xueting/path1", /* sizeof() == 1 */
        "eastup" : "/d/heifeng/lu1",
  "west" : __DIR__"ch_k11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
