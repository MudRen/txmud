// shroad3  �ϻ�·

inherit ROOM;

void create()
{
        set("short", "�ϻ�·");
        set("long", @LONG
�����ǳ����ǵ��ϻ�·���ǳ����������ֵ�֮һ�������ǽ�
�ڻʳǵ��ڻ�·�����Խ䱸ɭ�ϣ�Ѳ�������־��������ϣ�����
�ߴ�Ĺ�ǽ��ʾ���ޱȵĻ���������ǧ������Ȩ�������������
�ǻʹ�������פ���Ľ���Ӫ���ſ�������������Ľ������ء�
LONG
        );

	set("exits", ([
                "west"             : __DIR__"shroad2",
                "east"             : __DIR__"shroad4",
                "south"            : __DIR__"jinwei",
 ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
