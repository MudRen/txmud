// Room: /d/changan/shigong.c

inherit ROOM;

void create()
{
	set("short", "ʩ����");
	set("long", @LONG
�����ǹ������ŵ�ʩ���ӣ�һ�ߵ�����һ�ɺ���ζ���˱Ƕ�
����ֻ������׳���ڸ���������˵Ц�����濿ǽһ�ŷ������¡�
��ͷ�ĸ�ʽ���ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gongbu",
]));
	set(SAFE_ENV,1);
	set("no_sleep_room",1);

	setup();
	replace_program(ROOM);
}
