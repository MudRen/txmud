// ehroad2  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ����ǵĶ���·���ǳ����������ֵ�֮һ�������ǽ�
�ڻʳǵ��ڻ�·�����Խ䱸ɭ�ϣ�Ѳ�������־��������ϣ�һ��
�ϰ��ն�������������Ե÷ǳ��徻������ߴ�Ĺ�ǽ��ʾ��
�ޱȵĻ���������ǧ������Ȩ�������������Ķ������ֱͨ��
���ǵĶ��š�
LONG
        );

	set("exits", ([
                "east"             : __DIR__"eroad9",
                "south"            : __DIR__"ehroad1",
                "north"            : __DIR__"ehroad3",
]) );
	set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

        setup();
	replace_program(ROOM);
}
