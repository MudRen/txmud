// /d/changan/sroad4.c  �ϰ����

inherit ROOM;

void create()
{
        set("short", "�ϰ����");
        set("long", @LONG
���ǳ����ǵ��ϴ�֣��ӻʹ��������ص�ʥּ�͸����ͽ���
͢���������۶��������Ŵ��ݵģ������������ϵĹٱ���������
Ѳ���ܶ࣬�������վ����ˣ���Զ����ȻҲ��С�����������⣬
������ԶԶ�ıܿ��ٵ����Է���ŭ���ա����������Ͼ��ǳ�����
�����ţ�����������ǿ����Ļ����������Զ��������ͨ���ʹ�
���ϴ��š�
LONG
        );

	set("exits", ([
                "west"           : __DIR__"sroad3",
                "south"          : __DIR__"sdoor",
                "east"           : __DIR__"sroad5",
                "north"          : __DIR__"sroad9",
]) );
	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
