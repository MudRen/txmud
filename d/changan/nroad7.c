// /d/changan/nroad7  �����

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵĻ��У�����Ӧʱ���ʻ������﹩�����ء���
�ǲ�����¥Ҳ������һ��������ɢ���������������ȴ˵���徿
���ǻ��㻹��֬�۵���ζ����Զ����¥�ﴫ�������������Ц��
����������������ǳ����ı���֣����泤�������ļ�Ժ��
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad8",
                "south"           : __DIR__"jiyuan",
                "east"            : __DIR__"nroad6",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/gongzi" : 1,
	__DIR__"npc/genban" : 1,
]));
        setup();
	replace_program(ROOM);
}
