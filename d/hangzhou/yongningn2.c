// Room: /d/hangzhou/yongningn2.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yongningn1",
  "east" : __DIR__"linhouse",
  "north" : __DIR__"yongningn3",
]));


        set("objects",([
        NPC_DIR"xunpu" : 2,
	NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

	setup();
	replace_program(ROOM);
}
