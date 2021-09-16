// parry.c

inherit SKILL;

string *parry_msg = ({
	"ֻ�������ϡ���һ������$p��$v���ˡ�\n",
	"�����������һ����$p��$v�����ˡ�\n",
	"���Ǳ�$n�����е�$v�ܿ���\n",
	"����$n����һ�࣬�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
	"���Ǳ�$p���ˡ�\n",
	"�����$p�����ˡ�\n",
});

string query_parry_msg(object weapon,object weapon_v)
{
	if( weapon && weapon_v )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
