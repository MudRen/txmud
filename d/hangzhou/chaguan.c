// Room: /d/hangzhou/chaguan.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ���ª�Ĳ�ˮ���ӣ�װ�����Ǽ򵥣��ͳ����Ĳ�ׯ��
�ȼ�ֱ������֮�𣬵��۸�Ҳ���˵Ķ࣬���Գ����������Ͼʱ
����������Լ������Ʒ�����졣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"guotaiw3",
]));

	setup();
	replace_program(ROOM);
}
