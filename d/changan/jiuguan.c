// Room: /d/changan/jiuguan.c

inherit ROOM;

void create()
{
	set("short", "С�ƹ�");
	set("long", @LONG
����һ���ƾɼ�ª��С�ƹݣ�������ż���ľ���Σ�������
Ҫ�ľƲ�Ҳ�ܼ򵥣���Ŷ�����Χ��ƶ�񾭳�������
LONG
	);
	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad7",
]));

	set("objects",([
	__DIR__"npc/tiezui" : 1,
]));

	setup();
	replace_program(ROOM);
}
