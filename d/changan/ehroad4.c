// ehroad4  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ����ǵĶ���·���ǳ����������ֵ�֮һ�������ǽ�
�ڻʳǵ��ڻ�·�����Խ䱸ɭ�ϣ�Ѳ�������־��������ϡ�����
·�������������죬�����߾��Ǳ���·�ˡ�
LONG
        );

	set("exits", ([
                "south"            : __DIR__"ehroad3",
                "west"             : __DIR__"nhroad1",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 4,
]));

        setup();
	replace_program(ROOM);
}
