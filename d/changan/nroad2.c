// nroad2  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵı���ֵ���棬������񲢲�̫���֣���
��һ����ɱ�ĸо�������ż���Ҵ��߹����������������ߣ�һ��
���ϰ��մ�����������ط������������������������ھ֣��ſ�
վ���������ص��ǵ�׳�����������˶���һ�����ء�
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad3",
                "east"            : __DIR__"nroad1",
                "south"           : __DIR__"convoy",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

        setup();
	replace_program(ROOM);
}
