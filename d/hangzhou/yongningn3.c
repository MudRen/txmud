// Room: /d/hangzhou/yongningn3.c

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
  "west" : __DIR__"fruitshop",
  "south" : __DIR__"yongningn2",
  "north" : __DIR__"changanw4",
]));

	setup();
	replace_program(ROOM);
}
