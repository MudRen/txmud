// Room: /d/c/edoor.c

inherit ROOM;

void create()
{
	set("short", "�ɶ�����");
	set("long", @LONG
���������������ɶ��Ķ����ţ����ĳ�ǽ�ϰ߲��ĺۼ�
���Կ�������������ɣս�ҵ���ʷ����������Ȼ��̵������š�
�������ŵ��˴�����Ϣ����ʾ�Ž��յķ��������Ź��þ������
����ɨ����������������������ʱ����ס����������һ��������
�Ա�����һ�Ų���(bugao)��
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"fdjie3",
  "east" : __DIR__"out_chengdu_e",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["east" : __DIR__"out_chengdu_e"]) );
	set( "close_look",@LONG
���������������ɶ��Ķ����ţ�����������ʱ�䣬������
�������ˡ������ĵ�ֻ���سǵ�ʿ���ǻ������վ�����
LONG
);
	set( "gate_name","�ɶ�����" );
*/
	set("objects",([
		NPC_DIR"city_guard" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
