// Room: /d/c/ndoor.c

inherit ROOM;

void create()
{
	set("short", "�ɶ�����");
	set("long", @LONG
���������������ɶ��ı����ţ����ĳ�ǽ�ϰ߲��ĺۼ�
���Կ�������������ɣս�ҵ���ʷ����������Ȼ��̵������š�
�������ŵ��˴�����Ϣ����ʾ�Ž��յķ��������Ź��þ������
����ɨ����������������������ʱ����ס����������һ��������
�Ա�����һ�Ų���(bugao)��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shizi1",
  "north" : __DIR__"out_chengdu_n",
]));
	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"out_chengdu_n"]) );
	set( "close_look",@LONG
���������������ɶ��ı����ţ�����������ʱ�䣬������
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
