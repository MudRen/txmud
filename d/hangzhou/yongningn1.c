// Room: /d/hangzhou/yongningn1.c

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
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"butcherroom",
  "south" : __DIR__"yongning",
  "east" : __DIR__"doctorroom",
  "north" : __DIR__"yongningn2",
]));

	setup();
	replace_program(ROOM);
}
