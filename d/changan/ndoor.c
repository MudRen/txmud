// ndoor  ����

inherit ROOM;
void create()
{
        set("short", "�����Ǳ���");
        set("long", @LONG
�����ǳ����ǵı��ţ�������Ž����Ķ��Ǹ��������صİ�
�����������������ģ������ϳ��ơ��翸����̧���ֱ���������
��Ʒ���ſ������������������Ź��۵ò����ֺ����ڳ��ŵ�һ�ԣ�
����һ������(bugao)�������������ǳ����ǵı��������
LONG
        );

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([
		"north"	:	__DIR__"out_changan_n",
                "south"            : __DIR__"nroad4",
]) );

	// gate settings
	// �˲���Ϊ gate room �����������.

	// ���� gate room ���.ע�� GATE_ROOM Ҫ��д.
	set( "GATE_ROOM",1 );

	// ���� gate �ķ���,ע�ⷽ����һ�� mapping.
	set( "gate_dir",(["north" : __DIR__"out_changan_n"]) );

	// �����Ź����Ժ󿴵��ķ�������.
	// ����ͬ����ĳ�������.
	set( "close_look",@LONG
�����ǳ����ǵı��š�����������ʱ�䣬�����Ѿ������ˡ�
�����ĵ�ֻ���سǵ�ʿ���ǻ������վ�����
LONG
);

	// ���� gate ������,������ʱ�˷�������ҿ�������ʾҪ�õ�.
	set( "gate_name","�����Ǳ���" );

	// end.

	set("outdoors","changan");

	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));
	setup();
	replace_program(ROOM);
}