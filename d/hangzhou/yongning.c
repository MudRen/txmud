// Room: /d/hangzhou/yongning.c

inherit ROOM;

void create()
{
	set("short", "�����ֿ�");
	set("long", @LONG
�����������ֺ͹�̩·����ĵط��������򶫾��Ǻ��ݸ���
���ڵĹ�̩�֣��ϱ����ǱȽ��徲������·��
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"blacksmith",
  "south" : __DIR__"yongnings1",
  "east" : __DIR__"guotaiw3",
  "north" : __DIR__"yongningn1",
]));

	setup();
	replace_program(ROOM);
}
