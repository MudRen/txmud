// /d/changan/nhroad2  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ������ڻ�·���棬�ڻ�·���ڽ��ڻʹ��ڳǼ�֮��
�Ǹ����ŵ����ڵ����Խ���ɭ�ϣ���ʱ��Ѳ�Ǿ��Ӵ������߹���
����������Կ����ϱߵĽ�ˮ�ţ������ž��ǻʹ����ڵ��ſ�
�ˣ�����һ�Σ�����Դӱ��ų�������
LONG
        );
       set("exits", ([
                "west"             : __DIR__"nhroad3",
                "north"            : __DIR__"nroad9",
                "south"            : __DIR__"jingsq2",
                "east"             : __DIR__"nhroad1",
]) );
       set("outdoors","changan");
        setup();
	replace_program(ROOM);
}