// tang-force.c
// by Find.
// �����ڹ�

inherit FORCE;

void create()
{
	::create();
	set_yy(1);
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	mixed foo;
	/*int force;*/

	foo = ::hit_ob(me, victim, damage_bonus, factor);

	return foo;
}

string exert_function_file(string func)
{
	return CLASS_D("tangmen") + "/tang-force/" + func;
}

int valid_enable(string usage) 
{ 
	return	usage=="force";
}

int valid_learn(object me)
{
	return 1;
}

// �ڹ��Ƿ��д�͸���׵�����������ﴫ������ɽ��ţ֮��
int query_through_armor(object me,int factor)
{
	return 0;
/*
	int level,ret;

	if(!me || factor < 10)
		return 0;

	level = me->query_skill("tang-force",1);
	if(level < 50)
		return 0;

	ret = (level + factor)/5;
	return ret;
*/
}

/* ���书�Ƿ���ͨ����ϰ��������������Ϊ���� */
int practice_skill(object me)
{
        if(me->query_skill("tang-force",1) >= 250)
                return 1;
        else
                return notify_fail("����Ŀǰ�����ڹ�����Ϊ��ֻ��ͨ��ѧϰ����ߡ�\n");
}

int effective_level() { return 10; }

/* �˺�������ֵԽСԽ������Խ��Խ������0 Ϊ�����Ѷȡ�*/
/* ���ڴ��书����ͨ����ϰ���������Դ˵ش˺���û�ô��� */
int practice_bonus()
{
	return 0;
}


/* �˺�������ֵԽСԽ��ѧ��Խ��Խ��ѧ��0 Ϊ�����Ѷȡ�*/
int learn_bonus()
{
	return 0;
}

/* �������书С�� 75 ��ʱ���˺�������ֵԽСѧ��Խ�졣
 * �������书���� 75 ��ʱ���˺�������ֵԽ��ѧ��Խ�졣
 * �������书���� 75 ��ʱ���˺�������ֵû�����塣
 * Ҳ����˵�˺�������ֵС�����ڳ���ѧϰ����ԽѧԽ��
 * ��������ֵ�󣬳���ѧϰ���ѣ���ԽѧԽ��
 * ��������ֵΪ��������ǰ��׶��Ѷ�û�б仯
 */
int black_white_ness()
{
	return 0;
}
void drug_in_object()
{
  if(this_player())
          this_player()->apply_condition("tangdu",
                  this_player()->query_condition("tangdu")+10);
  return 0;
}

int valid_xiadu(
  object me,
  int level 
)
{
  if(intp(level) && level > 80)
          return 1;
  else
         return notify_fail("������Ŷ����ȼ�̫�ͣ�û���¶���\n");
}

