// Room: /d/huashan/xiaozi_feng.c

inherit ROOM;

void create()
{
	set("short", "Т�ӷ�");
	set("long", @LONG
һ�����ε�ɽ�������������ǰ�������Т�ӷ��ˡ���˵��
����ǰ�и��ж��յ�������������Ⱥ�һֱδ���ĸ�ף��쳤��
�ñ�ɵ�ʯͷ��
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xiaolu3",
  "southeast" : __DIR__"lin1",
]));
        set("outdoors", "huashan");

	set("objects",([
	__DIR__"npc/qiaofu" : 1,
]));

	setup();
	replace_program(ROOM);
}
