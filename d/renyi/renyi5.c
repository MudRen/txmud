// Room: /d/renyi/renyi5.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ��������С��·һֱ�������죬������ï�ܵ����ӣ�
���治Զ�����ܿ���һ�ȸߴ�����š�
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"renyi4",
  "southwest" : __DIR__"renyi6",
]));

	set("outdoors", "renyi");

	setup();
	replace_program(ROOM);
}
