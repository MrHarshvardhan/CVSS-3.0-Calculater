#include <stdio.h>
#include <string.h>

float calculate_base_score(char attack_vector, char attack_complexity, char privileges_required, char user_interaction, char scope) {
    float base_score = 0.0;

    // Base Score - Attack Vector
    if (attack_vector == 'N' || attack_vector == 'n')
        base_score += 0.85;
    else if (attack_vector == 'A' || attack_vector == 'a')
        base_score += 0.62;
    else if (attack_vector == 'L' || attack_vector == 'l')
        base_score += 0.55;
    else if (attack_vector == 'P' || attack_vector == 'p')
        base_score += 0.2;

    // Base Score - Attack Complexity
    if (attack_complexity == 'L' || attack_complexity == 'l')
        base_score += 0.77;
    else if (attack_complexity == 'H' || attack_complexity == 'h')
        base_score += 0.44;

    // Base Score - Privileges Required
    if (privileges_required == 'N' || privileges_required == 'n')
        base_score += 0.85;
    else if (privileges_required == 'L' || privileges_required == 'l')
        base_score += 0.68;
    else if (privileges_required == 'H' || privileges_required == 'h')
        base_score += 0.5;

    // Base Score - User Interaction
    if (user_interaction == 'N' || user_interaction == 'n')
        base_score += 0.85;
    else if (user_interaction == 'R' || user_interaction == 'r')
        base_score += 0.62;

    // Base Score - Scope
    if (scope == 'U' || scope == 'u')
        base_score += 0.0;
    else if (scope == 'C' || scope == 'c')
        base_score *= 1.08;

    return base_score;
}

float calculate_temporal_score(float base_score, char confidentiality, char integrity, char availability) {
    float temporal_score = base_score;

    // Environmental Score - Confidentiality Requirement
    if (confidentiality == 'H' || confidentiality == 'h')
        temporal_score *= 1.5;
    else if (confidentiality == 'L' || confidentiality == 'l')
        temporal_score *= 0.5;

    // Environmental Score - Integrity Requirement
    if (integrity == 'H' || integrity == 'h')
        temporal_score *= 1.5;
    else if (integrity == 'L' || integrity == 'l')
        temporal_score *= 0.5;

    // Environmental Score - Availability Requirement
    if (availability == 'H' || availability == 'h')
        temporal_score *= 1.5;
    else if (availability == 'L' || availability == 'l')
        temporal_score *= 0.5;

    return temporal_score;
}

int main() {
    // Base Score Metrics
    char attack_vector, attack_complexity, privileges_required, user_interaction, scope;

    // Get User Input
    printf("Enter the Attack Vector (options: Network[N], Adjacent[A], Local[L], Physical[P]): ");
    scanf(" %c", &attack_vector);
    printf("Enter the Attack Complexity (options: Low[L], High[H]): ");
    scanf(" %c", &attack_complexity);
    printf("Enter the Privileges Required (options: None[N], Low[L], High[H]): ");
    scanf(" %c", &privileges_required);
    printf("Enter the User Interaction (options: None[N], Required[R]): ");
    scanf(" %c", &user_interaction);
    printf("Enter the Scope (options: Unchanged[U], Changed[C]): ");
    scanf(" %c", &scope);

    float base_score = calculate_base_score(attack_vector, attack_complexity, privileges_required, user_interaction, scope);

    // Temporal Score Metrics
    float temporal_score = base_score;

    // Environmental Score Metrics
    char confidentiality, integrity, availability;
    printf("Enter the Confidentiality Requirement (options: High[H], Low[L], None[N]): ");
    scanf(" %c", &confidentiality);
    printf("Enter the Integrity Requirement (options: High[H], Low[L], None[N]): ");
    scanf(" %c", &integrity);
    printf("Enter the Availability Requirement (options: High[H], Low[L], None[N]): ");
    scanf(" %c", &availability);

    temporal_score = calculate_temporal_score(base_score, confidentiality, integrity, availability);

    // Calculate CVSS Vector String
    printf("\nBase Score: %.1f\n", base_score);
    printf("Temporal Score: %.1f\n", temporal_score);
    printf("CVSS v3.0 Vector: CVSS:3.1/AV:%c/AC:%c/PR:%c/UI:%c/S:%c/C:%c/I:%c/A:%c\n",
           attack_vector, attack_complexity, privileges_required, user_interaction, scope, confidentiality, integrity, availability);

    return 0;
}
