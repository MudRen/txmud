// Room: /wiz/louth/a/fyyg.c

inherit ROOM;

void create()
{
	set("short", "���Ÿ�");
	set("long", @LONG
����һ�䲼�õ��ŵ�С��������ͱ�����ű���������ɴ�ʣ�
�м���һ�ź�ľ�������������ϰ���һ�ܹ��١�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"hqinshi.c",
  "out" : __DIR__"yu53",
  "west" : __DIR__"hxiaoyuan.c",
]));
	set(SAFE_ENV,1);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huaner" : 1,
]));

	setup();
	replace_program(ROOM);
}
