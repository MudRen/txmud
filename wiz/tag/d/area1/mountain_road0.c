///////////////////////////////////////////////////
//�µ�����area1
//mountain_road0.c

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��Ŭ������ɽ����ȥ�������վ���ɽ��ʹ�㲻������
�����������ÿһ��������Ҫ���ݡ�׼ȷ��������
LONG
        );
        set("outdoors", "area1");
        set(SAFE_ENV, 1);
        set("no_sleep_room",1);
        
        setup();
        replace_program(ROOM);
}
///////////////////////////////////////////////////
