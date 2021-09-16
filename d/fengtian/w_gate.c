// Room: /d/fengtian/w_gate.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ƿ�������Ż���Ҳ�Ƿ���������Լ��ɹŵ������Ӹ�
�����Ż����ڳ��ŵ�һ�ԣ�����һ������(bugao)��������û��
������ô��ΰ������Ҳ�Ǳ���ɭ���ˣ����ٹٱ������������
��·�ˡ�
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guanlu1",
  "west" : __DIR__"out_fengtian_w",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["west" : __DIR__"out_fengtian_w"]) );
	set( "close_look",@LONG
�����Ƿ�������Ż���Ҳ�Ƿ���������Լ��ɹŵ������Ӹ�
�����Ż����ڳ��ŵ�һ�ԣ�����һ������(bugao)������������
ʱ�䣬�����Ѿ������ˡ������ĵ�ֻ���سǵ�ʿ���ǻ������վ
�����
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
