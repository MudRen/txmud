// doctor.c
// ҽ������ֻ�Ǽ�������Ļָ�(eff_ ��Чֵ�Ļָ�),
// ����һ���� call ��. ͨ�� heal_up ��� condition
// ʵ�� '����'.

// ���ɱ�� DOCTOR npc �����е�ҽ���ܳ�ʱ��(72 Сʱ)��������������ˡ��ⶾ��

// by Find.

#define PAY	2000	/* ҽ��20������ */

inherit NPC;
/* һ��� doctor Ҳ����ҩ���ϰ�֮��� npc Ϊͬһ�����
 * �˴��̳��� NPC ������� DOCTOR �� DEALER ���ܺ��壬
 * ����Ƿ�̳��д����á�
 */

nomask int is_doctor() {return 1;}
private void do_cure( object me, string what );

void init()
{
	::init();
	add_action("do_ask", "ask");
}

int do_ask( string arg )  /* return 0 let ask command process this action. */
{
	object me = this_player();
	string name, what;
	int f;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !arg || !stringp(arg) )
		return 0;

	if( sscanf( arg, "%s about %s", name, what ) != 2 )
		return 0; 

	if( !id(name) )
		return 0;

	if( what != "����" && what != "�ⶾ" )
		return 0;

	if( what == "����"
	&& me->query("eff_kee") >= me->query("max_kee")
	&& me->query("eff_gin") >= me->query("max_gin")
	&& me->query("eff_sen") >= me->query("max_sen") )
	{
		write(sprintf("%s��������һ��˵������λ%s��ɫ����û������ѽ��\n",
			name(),RANK_D->query_respect(me)));
		return 1;
	}

	if( what == "�ⶾ" && !me->query_condition("snake_poison") )
	{
		write(sprintf("%sҡҡͷ˵������ֻ���߶��е���գ������ľ�����Ϊ���ˡ�\n",name()));
		return 1;
	}

	if(me->query("doctor/kill_doctor"))
	{
		if(time() - me->query("doctor/kill_doctor") <=0 )
		{
			write(sprintf("%s��ݺݵĿ�����˵���������������׼��񵽶�����ҽ���¶��֣��Ҳ�����㿴���ģ���\n",
				name()));
			return 1;
		}

		else
			me->delete("doctor/kill_doctor");
	}

	if( me->query("age") <= PROTECT_AGE ) /* �ܱ����������. */
	{
		write(sprintf("%s���˿���˵��������ô��ĺ��Ӿ�%s���������ҽ��������ˡ���\n",
			name(),what == "����"?"���˳�����":"�����˶�"));
		do_cure(me, what);
		return 1;
	}

	if( me->query_condition("heal_up") )
	{
		write(name()+"˵���������ϴο����õ�ҩ��û��ʧЧ����������ҩ�ˣ�������������ɡ���\n");
		return 1;
	}

	if( ! f = player_pay(me,PAY) || f == 2)
	{
		write(sprintf("%s����üͷ˵������ûǮ�Ҿ�û�취�ˣ���ȥ��%s�ɡ���\n",
			name(),chinese_value(PAY)));
		return 1;
	}

	do_cure(me, what);
	return 1;
}

private void do_cure( object me, string what )
{
	switch( what )
	{
		case "����" :
			write(sprintf("%s�˳�һ����ҩ���������ȥ��Ȼ��˵�������ú���Ϣ��������ͻ�õġ���\n",name()));
			me->apply_condition("heal_up", 20 );
			break;

		case "�ⶾ" :
			/* ����һ��Ķ���ɺ���������ϣ�����Ķ�Ӧ���ɱ��˵����ƽ�ҩ�������н����*/

			write(name()+"�˳�һ��ҩ��������ֿ��˿���˵���������ˣ������ڵĶ��Ѿ��ξ��ˡ���\n");
			me->clear_condition("snake_poison");
			break;
        }
}