// Room: /d/hangzhou/yongnings1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǻ��ݳǱȽ�ƫƧ�ĵط������Ҳ�Ƚ��徻���������ֿ���
�������Ӻ��ϣ����ݸ��Ĵ������Ա��Ҳס���������ϡ�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"stoneroad1",
  "east" : __DIR__"pathy1",
  "north" : __DIR__"yongning",
]));

	setup();
	replace_program(ROOM);
}
