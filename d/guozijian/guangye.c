// Room: /d/guozijian/guangye.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "��ҵ��");
	set("long", @LONG
�����ǹ�ҵ�ã��Ǽ���ѧϰ�ĵط�����������Ҫ����������
�ݼס��������У���������͢�߼��佫�ĵط����⼸�տ�������
ʦ���ˣ�����û�п��Ρ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"xiudao",
]));
	set("objects", ([
		__DIR__"npc/wuguan"  : 1,
	]));
	setup();
	replace_program(ROOM);
}
