// Room: /d/fengtian/s_gate.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�������Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭ
ͷ���С���������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ���
�ء���������������׽��֮��Ĺٸ�����(bugao)��
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guanlu3",
  "south" : __DIR__"out_fengtian_s",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_fengtian_s"]) );
	set( "close_look",@LONG
�������Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭ
ͷ���С�������������Ѿ������ˡ������ĵ�ֻ���سǵ�ʿ����
�������վ�����
LONG
);
	set( "gate_name","���츮����" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));

	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
