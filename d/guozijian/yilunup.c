// Room: /d/guozijian/yilunup.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "�����ö�¥");
	set("long", @LONG
�����������õĶ�¥������ǽ�ϳ��˹���һ����������֮��
�Ļ��������������һ��ľ�Ƶ����ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"yilun",
]));

	setup();
	replace_program(ROOM);
}
