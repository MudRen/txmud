// whroad2  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
����ĳ����ǵ�����·���ǳ������������ֵ�֮һ��������
�ڽ��ڻʹ������Ǹ����ŵ����ڵ�����ʱʱ���䱸ɭ�ϣ�һ����
���ն���Ը������������������ֱͨ�����ǵ����š�
LONG
        );

	set("exits", ([
                "west"             : __DIR__"wroad9",
                "north"            : __DIR__"whroad1",
                "south"            : __DIR__"whroad3",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

        setup();
	replace_program(ROOM);
}
